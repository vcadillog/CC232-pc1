#pragma once

#include <cassert>
#include <vector>

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

    Node* getNode(int i) {
        assert(0 <= i && i <= n);
        Node* p;
        if (i < n / 2) {
            p = dummy.next;
            for (int j = 0; j < i; ++j) p = p->next;
        } else {
            p = &dummy;
            for (int j = n; j > i; --j) p = p->prev;
        }
        return p;
    }

    const Node* getNode(int i) const {
        assert(0 <= i && i <= n);
        const Node* p;
        if (i < n / 2) {
            p = dummy.next;
            for (int j = 0; j < i; ++j) p = p->next;
        } else {
            p = &dummy;
            for (int j = n; j > i; --j) p = p->prev;
        }
        return p;
    }

    Node* addBefore(Node* w, const T& x) {
        Node* u = new Node{x, w->prev, w};
        u->prev->next = u;
        u->next->prev = u;
        ++n;
        return u;
    }

    void removeNode(Node* w) {
        w->prev->next = w->next;
        w->next->prev = w->prev;
        delete w;
        --n;
    }

public:
    DLList() : n(0) {
        dummy.next = &dummy;
        dummy.prev = &dummy;
    }

    DLList(const DLList& other) : DLList() {
        for (const Node* u = other.dummy.next; u != &other.dummy; u = u->next) {
            add(u->x);
        }
    }

    DLList& operator=(const DLList& other) {
        if (this != &other) {
            clear();
            for (const Node* u = other.dummy.next; u != &other.dummy; u = u->next) {
                add(u->x);
            }
        }
        return *this;
    }

    DLList(DLList&& other) noexcept : DLList() {
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

    DLList& operator=(DLList&& other) noexcept {
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

    ~DLList() {
        clear();
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    void clear() {
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

    T front() const {
        assert(n > 0);
        return dummy.next->x;
    }

    T back() const {
        assert(n > 0);
        return dummy.prev->x;
    }

    T get(int i) const {
        assert(0 <= i && i < n);
        return getNode(i)->x;
    }

    T set(int i, const T& x) {
        assert(0 <= i && i < n);
        Node* u = getNode(i);
        T y = u->x;
        u->x = x;
        return y;
    }

    void add(int i, const T& x) {
        assert(0 <= i && i <= n);
        addBefore(getNode(i), x);
    }

    void add(const T& x) {
        add(n, x);
    }

    T remove(int i) {
        assert(0 <= i && i < n);
        Node* w = getNode(i);
        T x = w->x;
        removeNode(w);
        return x;
    }

    bool checkSize() const {
        int count = 0;
        const Node* u = dummy.next;
        const Node* prev = &dummy;
        while (u != &dummy) {
            if (u->prev != prev) {
                return false;
            }
            prev = u;
            u = u->next;
            ++count;
        }
        return count == n && dummy.prev == prev;
    }
};

} // namespace ods
