#pragma once
#include <cassert>

namespace ods {

template<class T>
class DLList {
protected:
    struct Node {
        T x;
        Node* prev;
        Node* next;
    };

    Node dummy;
    int n;

    Node* getNode(int i);
    const Node* getNode(int i) const;

    Node* addBefore(Node* w, const T& x);
    void removeNode(Node* w);

public:
    DLList();
    DLList(const DLList& other);
    DLList& operator=(const DLList& other);
    bool operator==(const DLList& other) const;

    DLList(DLList&& other) noexcept;
    DLList& operator=(DLList&& other) noexcept;

    ~DLList();

    int size() const;
    bool empty() const;

    void clear();

    T front() const;
    T back() const;

    T get(int i) const;
    T set(int i, const T& x);

    void add(int i, const T& x);
    void add(const T& x);

    T remove(int i);

    bool checkSize() const;
};

} // namespace ods
