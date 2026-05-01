#include "MultiLevelDLList.h"
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
  std::cout << "Creación manual del DLList multinivel\n";
  list.print();
  std::cout << list.size() << " nodos en total\n";
  std::cout << "\n";

  std::cout << "Agregado un hijo en el nodo 2\n";
  if (list.addChild(2) == nullptr) {
    std::cout << "Restricción: no creó child\n";
  }
  std::cout << "\n";

  DLList<int> result = list.flatten();

  std::cout << "Flatten: ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << result.get(i) << " ";
  }
  std::cout << "\n\n";

  std::cout << "Eliminando el nodo padre 2\n";
  list.remove(2);

  list.print();
  std::cout << list.size() << " nodos en total\n\n";

  DLList<int> result2 = list.flatten();

  std::cout << "Después de remove(2): ";
  for (int i = 0; i < result2.size(); i++) {
    std::cout << result2.get(i) << " ";
  }
  std::cout << "\n\n";

  std::cout << "Creación del DLList multinivel usando un string\n";
  //std::string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]";
  std::string input = "[1,2,3,4,5,6,null,null,null,null,7,8,9,10,null,null,null,11,12,13,14]";

  std::cout << "Input: " << input << "\n";

  MultiLevelDLList<int> list2;

  list2.buildFromString(input);
  list2.print();

  std::cout << list2.size() << " nodos en total\n";

  DLList<int> result3 = list2.flatten();

  std::cout << "Flatten: ";
  for (int i = 0; i < result3.size(); i++) {
    std::cout << result3.get(i) << " ";
  }
  std::cout << "\n\n";

  std::cout << "Limpiando los nodos\n";
  list2.clear();
  std::cout << list2.size() << " nodos en total\n\n";

  return 0;
}
