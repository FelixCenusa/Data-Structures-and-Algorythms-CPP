#ifndef ORDEREDLIST_HPP
#define ORDEREDLIST_HPP

#include <stdexcept>

template <class T>
class OrderedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    int num_elements;

public:
    OrderedList();
    ~OrderedList();
    OrderedList(const OrderedList& other) = delete;
    OrderedList& operator=(const OrderedList& other) = delete;
    
    int size() const;
    bool is_empty() const;
    void add(const T& element);
    T remove(const T& element);
    T removeAt(int index);
    T removeFirst();
    T removeLast();
    T get(const T& element) const;
    T first() const;
    T last() const;
};

#endif

template <class T>
OrderedList<T>::OrderedList() : 
	front(nullptr), num_elements(0) 
{

}
template <class T>
OrderedList<T>::~OrderedList() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}
template <class T>
int OrderedList<T>::size() const {
    // Returns size of OrderedList
    return -1;
}
template <class T>
bool OrderedList<T>::is_empty() const {
    // Returns if OrderedList is empty or now
    return false;
}
template <class T>
void OrderedList<T>::add(const T& element) {
    // Adds element to the OrderedList in its correct place
}
template <class T>
T OrderedList<T>::remove(const T& element) {
    // Removes and returns specific element from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::removeAt(int index) {
    // Removes and returns element at specific index from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::removeFirst() {
    // Removes and returns the first element from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::removeLast() {
    // Removes and returns the last element from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::get(const T& element) const {
    // Returns a specific element in the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::first() const {
    // Returns the first element in the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::last() const {
    // Returns the last element in the OrderedList
    return T();
}