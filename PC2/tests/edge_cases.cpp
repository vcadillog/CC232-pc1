#include "MultiLevelDLList.h"
#include <cassert>
#include <iostream>

using namespace ods;

int main() {

  MultiLevelDLList<int> list;
  DLList<int> dllist;
  DLList<int> result = list.flatten();
  assert(result == dllist);
  assert(result.size() == dllist.size());
  assert(result.size() == 0);
  assert(result.checkSize());
  assert(result.empty());

  list.clear();
  assert(list.size() == 0);

  list.add(1);
  dllist.add(1);
  assert(list == dllist);
  assert(list.size() == dllist.size());
  assert(list.size() == 1);
  dllist.clear();
  list.clear();

  std::string input = "[]";
  list.buildFromString(input);
  result = list.flatten();
  assert(result == dllist);
  assert(result.size() == 0);

  input = "[1,null,2,null,3,null,4,null,5]";
  list.buildFromString(input);
  // 1,2,3,7,8,11,13,14,16,18,19,20,21,17,15,12,9,10,4,5,6
  result = list.flatten();
  dllist.clear();
  for (int i = 1; i <= 5; i++) {
    dllist.add(i);
  }
  assert(result == dllist);
  assert(result.size() == 5);

  list.add(6);
  list.add(7);
  list.remove(0);
  dllist.clear();
  dllist.add(6);
  dllist.add(7);
  assert(list == dllist);
  assert(list.size() == 2);

  list.remove(0);
  dllist.remove(0);
  assert(list == dllist);
  assert(list.size() == 1);

  list.add(8);
  list.add(9);
  list.add(10);
  list.add(11);

  auto *child1 = list.addChild(4);
  if (child1 != nullptr) {
    child1->add(1);
    child1->add(2);
    child1->add(3);
    child1->add(4);
  }
  result = list.flatten();
  dllist.add(8);
  dllist.add(9);
  dllist.add(10);
  dllist.add(11);
  dllist.add(1);
  dllist.add(2);
  dllist.add(3);
  dllist.add(4);
  assert(result == dllist);
  assert(result.size() == 9);

  list.remove(4);
  dllist.remove(8);
  dllist.remove(7);
  dllist.remove(6);
  dllist.remove(5);
  dllist.remove(4);
  assert(list == dllist);
  assert(list.size() == 4);

  list.clear();
  dllist.clear();
  //
  input = "[1,2,3,4,5,6,null,7,null,8,null,9,null,10]";
  result = list.buildFromString(input);
  // [2,3,4,5,6]
  result.remove(0);
  for (int i = 2; i <= 6; i++) {
    dllist.add(i);
  }
  assert(result == dllist);
  assert(result.size() == dllist.size());
  assert(result.size() == 5);
  return 0;
}
