#include "DLList.h"

namespace ods {

template<class T>
DLList<T>::DLList() : n(0) {
    dummy.next = &dummy;
    dummy.prev = &dummy;
}

template<class T>
DLList<T>::DLList(const DLList& other) : DLList() {
    for (const Node* u = other.dummy.next; u != &other.dummy; u = u->next) {
        add(u->x);
    }
}

template<class T>
DLList<T>& DLList<T>::operator=(const DLList& other) {
    if (this != &other) {
        clear();
        for (const Node* u = other.dummy.next; u != &other.dummy; u = u->next) {
            add(u->x);
        }
    }
    return *this;
}

template<class T>
DLList<T>::DLList(DLList&& other) noexcept : DLList() {
    if (!other.empty()) {
        dummy.next = other.dummy.next;
        dummy.prev = other.dummy.prev;
        dummy.next->prev = &dummy;
        dummy.prev->next = &dummy;
        n = other.n;

        other.dummy.next = &other.dummy;
        other.dummy.prev = &other.dummy;
        other.n = 0;
    }
}

template<class T>
DLList<T>& DLList<T>::operator=(DLList&& other) noexcept {
    if (this != &other) {
        clear();
        if (!other.empty()) {
            dummy.next = other.dummy.next;
            dummy.prev = other.dummy.prev;
            dummy.next->prev = &dummy;
            dummy.prev->next = &dummy;
            n = other.n;

            other.dummy.next = &other.dummy;
            other.dummy.prev = &other.dummy;
            other.n = 0;
        }
    }
    return *this;
}

template<class T>
DLList<T>::~DLList() {
    clear();
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
    assert(0 <= i && i <= n);
    Node* p;

    if (i < n/2) {
        p = dummy.next;
        for (int j = 0; j < i; j++) p = p->next;
    } else {
        p = &dummy;
        for (int j = n; j > i; j--) p = p->prev;
    }

    return p;
}

template<class T>
const typename DLList<T>::Node* DLList<T>::getNode(int i) const {
    assert(0 <= i && i <= n);
    const Node* p;

    if (i < n/2) {
        p = dummy.next;
        for (int j = 0; j < i; j++) p = p->next;
    } else {
        p = &dummy;
        for (int j = n; j > i; j--) p = p->prev;
    }

    return p;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node* w, const T& x) {
    Node* u = new Node{x, w->prev, w};
    u->prev->next = u;
    u->next->prev = u;
    ++n;
    return u;
}

template<class T>
void DLList<T>::removeNode(Node* w) {
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    --n;
}


template<class T>
int DLList<T>::size() const { return n; }

template<class T>
bool DLList<T>::empty() const { return n == 0; }

template<class T>
void DLList<T>::clear() {
    Node* u = dummy.next;
    while (u != &dummy) {
        Node* w = u->next;
        delete u;
        u = w;
    }
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
}

template<class T>
T DLList<T>::front() const {
    assert(n > 0);
    return dummy.next->x;
}

template<class T>
T DLList<T>::back() const {
    assert(n > 0);
    return dummy.prev->x;
}

template<class T>
T DLList<T>::get(int i) const {
    assert(0 <= i && i < n);
    return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, const T& x) {
    assert(0 <= i && i < n);
    Node* u = getNode(i);
    T y = u->x;
    u->x = x;
    return y;
}

template<class T>
void DLList<T>::add(int i, const T& x) {
    assert(0 <= i && i <= n);
    addBefore(getNode(i), x);
}

template<class T>
void DLList<T>::add(const T& x) {
    add(n, x);
}

template<class T>
T DLList<T>::remove(int i) {
    assert(0 <= i && i < n);
    Node* w = getNode(i);
    T x = w->x;
    removeNode(w);
    return x;
}

template<class T>
bool DLList<T>::checkSize() const {
    int count = 0;
    const Node* u = dummy.next;
    const Node* prev = &dummy;

    while (u != &dummy) {
        if (u->prev != prev) return false;
        prev = u;
        u = u->next;
        ++count;
    }

    return count == n && dummy.prev == prev;
}

template class DLList<int>;
template class DLList<double>;

} // namespace ods
