#include "MultiLevelDLList.h"
#include <cassert>

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

  std::string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]";
  MultiLevelDLList<int> list2;
  list2.buildFromString(input);
  assert(list == list2);

  assert(list.checkSize());
  DLList<int> result = list.flatten();

  DLList<int> dllist;
  for (int i = 1; i <= 3; i++) {
    dllist.add(i);
  }
  for (int i = 7; i <= 8; i++) {
    dllist.add(i);
  }
  for (int i = 11; i <= 12; i++) {
    dllist.add(i);
  }
  for (int i = 9; i <= 10; i++) {
    dllist.add(i);
  }
  for (int i = 4; i <= 6; i++) {
    dllist.add(i);
  }
  assert(result == dllist);
  assert(result.size() == dllist.size());
  assert(result.size() == 12);
  assert(result.checkSize());

  list.remove(2);

  result = list.flatten();
  dllist.clear();
  for (int i = 1; i <= 6; i++) {
    dllist.add(i);
  }
  dllist.remove(2);
  assert(list == dllist);
  assert(list.size() == dllist.size());
  assert(list.size() == 5);
  assert(list.checkSize());

  list.clear();
  input = "[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12,"
                      "null,13,14,15,null,null,16,17,"
                      "null,18,19,null,null,20,21]";
  list.buildFromString(input);
  // 1,2,3,7,8,11,13,14,16,18,19,20,21,17,15,12,9,10,4,5,6
  result = list.flatten();
  dllist.clear();
  dllist.add(1);
  dllist.add(2);
  dllist.add(3);
  dllist.add(7);
  dllist.add(8);
  dllist.add(11);
  dllist.add(13);
  dllist.add(14);
  dllist.add(16);
  dllist.add(18);
  dllist.add(19);
  dllist.add(20);
  dllist.add(21);
  dllist.add(17);
  dllist.add(15);
  dllist.add(12);
  dllist.add(9);
  dllist.add(10);
  dllist.add(4);
  dllist.add(5);
  dllist.add(6);

  assert(result == dllist);
  assert(result.size() == dllist.size());
  assert(result.size() == 21);
  assert(result.checkSize());

  list.clear();
  assert(list.size() == 0);


  input = "[1,2,3, null,13,14,15,null,16,17,null,18,19,null,null,20,21]";
  // [1,13,16,18,19,20,21,17,14,15,2,3]
  list.buildFromString(input);
  assert(list.size() == 12);
  result = list.flatten();
  assert(list.size() == result.size());

  return 0;
}
