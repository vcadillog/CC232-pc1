#include "MultiLevelDLList.h"
#include <chrono>
#include <iostream>

using namespace ods;
using namespace std::chrono;

template <class F> long long time_ms(F &&f) {
  auto start = high_resolution_clock::now();
  f();
  auto end = high_resolution_clock::now();
  return duration_cast<milliseconds>(end - start).count();
}

MultiLevelDLList<int> buildTree(int n) {
  MultiLevelDLList<int> list;

  for (int i = 1; i <= n; i++) {
    list.add(i);
  }

  int base = list.baseSize();

  for (int i = 0; i < base; i += 3) {

    if (i >= list.baseSize())
      break;

    auto *child = list.addChild(i);
    if (!child)
      continue;

    for (int j = 1; j <= 5; j++) {
      child->add(j);
    }

    if (child->size() > 0) {
      auto *grand = child->addChild(0);
      if (grand) {
        grand->add(100);
        grand->add(200);
      }
    }
  }

  return list;
}

int main() {

  std::cout << "==== BENCHMARK ====\n";

  int tests[] = {5000, 10000, 50000, 100000};

  for (int n : tests) {

    std::cout << "\nN = " << n << "\n";

    long long t_build = time_ms([&]() {
      auto list = buildTree(n);
      (void)list;
    });

    std::cout << "build: " << t_build << " ms\n";

    MultiLevelDLList<int> list = buildTree(n);

    long long t_flat = time_ms([&]() {
      auto res = list.flatten();
      (void)res;
    });

    std::cout << "flatten: " << t_flat << " ms\n";

    long long t_remove = time_ms([&]() {
      int sz = list.baseSize();

      if (sz > 5) {
        int idx = sz / 2;

        if (idx >= 0 && idx < list.baseSize()) {
          list.remove(idx);
        }
      }
    });

    std::cout << "remove: " << t_remove << " ms\n";

    long long t_check = time_ms([&]() { list.checkSize(); });

    std::cout << "checkSize: " << t_check << " ms\n";
  }

  return 0;
}
