#ifndef PRIORITYQUEUEHEAP_HPP
#define PRIORITYQUEUEHEAP_HPP

#include "Heap.hpp"
#include <stdexcept>

template <typename T>
class PriorityQueueHeap {
private:
    Heap<T> heap;

public:
    PriorityQueueHeap();
    ~PriorityQueueHeap() = default;
    PriorityQueueHeap(const PriorityQueueHeap& other) = delete;
    PriorityQueueHeap& operator =(const PriorityQueueHeap& other) = delete;

    int size() const;
    void enqueue(const T& element);
    T dequeue();
    T peek() const;
    bool is_empty() const;
};

#endif

template <class T>
PriorityQueueHeap<T>::PriorityQueueHeap()
{

}

template <class T>
int PriorityQueueHeap<T>::size() const {
    // Returns size of PQ
    return heap.size();
}

template <class T>
void PriorityQueueHeap<T>::enqueue(const T& element) {
    // Add to PQ
}

template <class T>
T PriorityQueueHeap<T>::dequeue() {
    // Remove and return next element from PQ
    return T();
}

template <class T>
T PriorityQueueHeap<T>::peek() const {
    // Returns next element from PQ
    return T();
}

template <class T>
bool PriorityQueueHeap<T>::is_empty() const {
    // Returns if empty or not
    return false;
}