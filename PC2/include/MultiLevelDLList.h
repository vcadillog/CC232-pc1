#pragma once
#include "DLList.h"
#include <string>
#include <unordered_map>
#include <vector>

const int mMax = 100000;

namespace ods {

template <class T>
class MultiLevelDLList : public DLList<T> {
protected:
    using Node = typename DLList<T>::Node;

    int m;
    std::unordered_map<Node*, MultiLevelDLList<T>*> children;
    MultiLevelDLList<T>* parent;

    MultiLevelDLList<T>* getChild(Node* u) const;

public:
    MultiLevelDLList();
    ~MultiLevelDLList();

    void incrementUp(int k = 1);
    void decrementUp(int k);

    void add(int i, const T& x);
    void add(const T& x);

    MultiLevelDLList<T>* addChild(int i);
    bool hasChild(int i);

    void removeNode(Node* w);
    T remove(int i);

    int size() const;

    bool checkSize() const;

    void clear();

    void flatten(std::vector<T>& result) const;
    std::vector<T> flatten() const;

    std::vector<std::string> parse(const std::string& s);
    MultiLevelDLList<T>& buildFromString(const std::string& input);
};

} // namespace ods
