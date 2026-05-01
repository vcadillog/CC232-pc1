#include "MultiLevelDLList.h"
#include <cassert>
#include <iostream>

using namespace ods;

int main() {

  MultiLevelDLList<int> list;

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

  assert(list.checkSize());
  DLList<int> result = list.flatten();

  DLList<int> dllist1;
  for (int i = 1; i <= 3; i++) {
    dllist1.add(i);
  }
  for (int i = 7; i <= 8; i++) {
    dllist1.add(i);
  }
  for (int i = 11; i <= 12; i++) {
    dllist1.add(i);
  }
  for (int i = 9; i <= 10; i++) {
    dllist1.add(i);
  }
  for (int i = 4; i <= 6; i++) {
    dllist1.add(i);
  }
  assert(result == dllist1);
  assert(result.size() == dllist1.size());
  assert(result.size() == 12);
  assert(result.checkSize());

  list.remove(2);

  DLList<int> result2 = list.flatten();
  DLList<int> dllist2;
  for (int i = 1; i <= 6; i++) {
    dllist2.add(i);
  }
  dllist2.remove(2);
  assert(list == dllist2);
  assert(list.size() == dllist2.size());
  assert(list.size() == 5);
  assert(list.checkSize());

  std::string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12,"
                      "null,13,14,15,null,null,16,17,"
                      "null,18,19,null,null,20,21]";
  std::cout << input << "\n";
  MultiLevelDLList<int> list2;
  list2.buildFromString(input);
  list2.print();
  // 1,2,3,7,8,11,13,14,16,18,19,20,21,17,15,12,9,10,4,5,6
  DLList<int> result3 = list2.flatten();
  DLList<int> dllist3;
  dllist3.add(1);
  dllist3.add(2);
  dllist3.add(3);
  dllist3.add(7);
  dllist3.add(8);
  dllist3.add(11);
  dllist3.add(13);
  dllist3.add(14);
  dllist3.add(16);
  dllist3.add(18);
  dllist3.add(19);
  dllist3.add(20);
  dllist3.add(21);
  dllist3.add(17);
  dllist3.add(15);
  dllist3.add(12);
  dllist3.add(9);
  dllist3.add(10);
  dllist3.add(4);
  dllist3.add(5);
  dllist3.add(6);

  assert(result3 == dllist3);
  assert(result3.size() == dllist3.size());
  assert(result3.size() == 21);
  assert(result3.checkSize());

  list2.clear();
  assert(list2.size() == 0);

  return 0;
}
