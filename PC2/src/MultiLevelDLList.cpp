#include "MultiLevelDLList.h"
#include "iomanip"
#include <cassert>
#include <cctype>
#include <iostream>

namespace ods {

template <class T>
MultiLevelDLList<T> *MultiLevelDLList<T>::getChild(Node *u) const {
  auto it = children.find(u);
  return (it != children.end()) ? it->second : nullptr;
}

template <class T>
MultiLevelDLList<T>::MultiLevelDLList() : DLList<T>(), m(0), parent(nullptr) {}

template <class T> MultiLevelDLList<T>::~MultiLevelDLList() {
  for (auto &p : children)
    delete p.second;
}

template <class T> void MultiLevelDLList<T>::incrementUp(int k) {
  auto *p = this;
  while (p) {
    p->m += k;
    p = p->parent;
  }
}

template <class T> void MultiLevelDLList<T>::decrementUp(int k) {
  auto *p = this;
  while (p) {
    p->m -= k;
    p = p->parent;
  }
}

template <class T> void MultiLevelDLList<T>::add(int i, const T &x) {
  assert(0 <= i && i <= mMax);
  DLList<T>::add(i, x);
  incrementUp(1);
}

template <class T> void MultiLevelDLList<T>::add(const T &x) {
  DLList<T>::add(this->n, x);
  incrementUp(1);
}

template <class T> MultiLevelDLList<T> *MultiLevelDLList<T>::addChild(int i) {
  Node *u = this->getNode(i);

  if (getChild(u))
    return nullptr;

  auto *child = new MultiLevelDLList<T>();
  child->parent = this;
  children[u] = child;

  return child;
}

template <class T> bool MultiLevelDLList<T>::hasChild(int i) {
  return getChild(this->getNode(i)) != nullptr;
}

template <class T> void MultiLevelDLList<T>::removeNode(Node *w) {
  int removed = 1;

  auto *child = getChild(w);
  if (child) {
    removed += child->m;
    delete child;
    children.erase(w);
  }

  w->prev->next = w->next;
  w->next->prev = w->prev;
  delete w;
  this->n--;

  decrementUp(removed);
}

template <class T> T MultiLevelDLList<T>::remove(int i) {
  assert(0 <= i && i < this->n);
  Node *w = this->getNode(i);
  T x = w->x;
  removeNode(w);
  return x;
}

template <class T> int MultiLevelDLList<T>::size() const { return m; }
template <class T> int MultiLevelDLList<T>::baseSize() const { return this->n; }

template <class T> bool MultiLevelDLList<T>::checkSize() const {
  int total = 0;

  struct StackNode {
    const MultiLevelDLList<T> *list;
    StackNode *next;
  };

  StackNode *stack = new StackNode{this, nullptr};

  while (stack) {
    auto *list = stack->list;
    auto *tmp = stack;
    stack = stack->next;
    delete tmp;

    total += list->n;

    Node *u = list->dummy.next;
    while (u != &list->dummy) {
      auto it = list->children.find(u);
      if (it != list->children.end()) {
        stack = new StackNode{it->second, stack};
      }
      u = u->next;
    }
  }

  return total == m;
}

template <class T> void MultiLevelDLList<T>::clear() {
  for (auto &p : children)
    delete p.second;
  children.clear();

  DLList<T>::clear();
  m = 0;
}

template <class T> void MultiLevelDLList<T>::flatten(DLList<T> &result) const {
  Node *u = this->dummy.next;

  while (u != &this->dummy) {
    result.add(u->x);

    if (auto *child = getChild(u)) {
      child->flatten(result);
    }

    u = u->next;
  }
}

template <class T> DLList<T> MultiLevelDLList<T>::flatten() const {
  DLList<T> res;
  flatten(res);
  return res;
}

template <class T>
std::vector<std::string> MultiLevelDLList<T>::parse(const std::string &s) {
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

template <class T>
MultiLevelDLList<T> &
MultiLevelDLList<T>::buildFromString(const std::string &input) {
  auto input_parsed = parse(input);
  this->clear();

  if (input_parsed.empty())
    return *this;

  int i = 0;

  while (i < input_parsed.size() && input_parsed[i] != "null") {
    this->add(std::stoi(input_parsed[i]));
    i++;
  }

  i++;

  std::vector<std::pair<MultiLevelDLList<T> *, int>> stack;

  for (int j = this->n - 1; j >= 0; --j) {
    stack.push_back({this, j});
  }

  while (!stack.empty() && i < input_parsed.size()) {
    auto [list, idx] = stack.back();
    stack.pop_back();

    if (i >= input_parsed.size())
      break;

    if (input_parsed[i] == "null") {
      i++;
      continue;
    }

    auto *child = list->addChild(idx);

    std::vector<int> values;
    while (i < input_parsed.size() && input_parsed[i] != "null") {
      values.push_back(std::stoi(input_parsed[i]));
      i++;
    }

    for (int v : values)
      child->add(v);

    for (int j = child->n - 1; j >= 0; --j) {
      stack.push_back({child, j});
    }

    if (i < input_parsed.size())
      i++;
  }

  return *this;
}

template <class T> void MultiLevelDLList<T>::print() const {
  using Node = typename DLList<T>::Node;

  struct Item {
    const MultiLevelDLList<T> *list;
    Node *node;
    int pos;
    int depth;
  };

  std::vector<Item> stack;
  std::vector<std::vector<std::string>> levels;

  int idx = 0;
  for (Node *u = this->dummy.next; u != &this->dummy; u = u->next) {
    stack.push_back({this, u, idx++, 0});
  }

  while (!stack.empty()) {
    auto cur = stack.back();
    stack.pop_back();

    if (levels.size() <= cur.depth)
      levels.resize(cur.depth + 1);

    auto &lvl = levels[cur.depth];

    if (lvl.size() <= cur.pos)
      lvl.resize(cur.pos + 1, "null");

    lvl[cur.pos] = std::to_string(cur.node->x);

    auto it = cur.list->children.find(cur.node);
    if (it == cur.list->children.end())
      continue;

    const MultiLevelDLList<T> *child = it->second;

    int childPos = cur.pos;

    for (Node *c = child->dummy.next; c != &child->dummy; c = c->next) {
      if (levels.size() <= cur.depth + 1)
        levels.resize(cur.depth + 2);

      auto &nextLvl = levels[cur.depth + 1];

      if (nextLvl.size() <= childPos)
        nextLvl.resize(childPos + 1, "null");

      stack.push_back({child, c, childPos, cur.depth + 1});
      childPos++;
    }
  }

  for (auto &lvl : levels) {
    std::cout << "[";

    for (size_t i = 0; i < lvl.size(); i++) {
      std::cout << std::setw(6) << lvl[i];
      if (i + 1 < lvl.size())
        std::cout << ", ";
    }

    std::cout << "]\n";
  }
}

template class MultiLevelDLList<int>;

} // namespace ods
