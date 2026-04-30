#include "MultiLevelDLList.h"
#include <iostream>
#include <vector>

using namespace ods;

std::vector<std::string> parse(const std::string &s) {
  std::vector<std::string> result;
  std::string token;

  for (char c : s) {
    if (c == '[' || c == ']')
      continue;

    if (c == ',') {
      if (!token.empty()) {
        result.push_back(token);
        token.clear();
      }
    } else if (!isspace(c)) {
      token += c;
    }
  }

  if (!token.empty())
    result.push_back(token);

  return result;
}

int main() {

  MultiLevelDLList<int> list;

  // Nivel 0: [1,2,3,4,5,6]
  for (int i = 1; i <= 6; i++) {
    list.add(i);
  }

  auto *child1 = list.addChild(2);

  if (child1 != nullptr) {
    child1->add(7);
    child1->add(8);
    child1->add(9);
    child1->add(10);
  }

  auto *child2 = child1->addChild(1);

  if (child2 != nullptr) {
    child2->add(11);
    child2->add(12);
  }
  std::cout << list.sizeDeep() << " elementos en total\n";

  auto *failChild = list.addChild(2);
  if (failChild == nullptr) {
    std::cout << "Restricción OK: no duplicó child\n";
  }

  std::vector<int> result = list.flatten();

  std::cout << "Flatten: ";
  for (int x : result) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  std::vector<int> expected = {1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6};

  bool ok = (result == expected);
  std::cout << "Resultado: " << (ok? "Correcto" : "Fallo") << "\n";

  list.remove(2); 

  auto result2 = list.flatten();

  std::cout << "Después de remove(2): ";
  for (int x : result2) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  // esperado: 1 2 4 5 6
  std::vector<int> expected2 = {1, 2, 4, 5, 6};

  bool ok2 = (result2 == expected2);
  std::cout << "Resultado: " << (ok2? "Correcto" : "Fallo") << "\n";

  std::string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]";
  //std::string input = "[1,2,3,4,5,6,7,null,null,null,null,null,8,9,10,11,null,null,12,13]";
  //std::string input = "[1,2,null,3]";
  //std::string input = "[]";

  auto tokens = parse(input);
  for (const auto &t : tokens) {
    std::cout << t << " ";
  }
  std::cout << "\n";

  MultiLevelDLList<int> list2;

  list2.buildFromString(tokens);

  std::vector<int> result3 = list2.flatten();

  std::cout << "Flatten: ";
  for (int x : result3) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  bool ok3 = (result3 == expected);
  std::cout << "Resultado: " << (ok3? "Correcto" : "Fallo") << "\n";

  return 0;
}
