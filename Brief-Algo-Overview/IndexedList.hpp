#ifndef INDEXEDLIST_HPP
#define INDEXEDLIST_HPP

#include <stdexcept>

template <class T>
class IndexedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(T data = nullptr) : data(data), next(nullptr) {}
    };
    Node* front;
    int num_elements;
public:
    IndexedList();
    ~IndexedList();
    IndexedList(const IndexedList& other) = delete;
    IndexedList& operator=(const IndexedList& other) = delete;
    
    int size() const;
    bool is_empty() const;
    T getAt(int index) const;
    void addAt(int index, const T& element);
    T removeFirst();
    T removeAt(int index);
    T removeLast();
    T first() const ;
    T last() const;
};

#endif

template<class T>
IndexedList<T>::IndexedList() : 
    front(nullptr), num_elements(0)
{

}

template <class T>
IndexedList<T>::~IndexedList()
{
    while (this->front != nullptr)
    {
        Node *temp = this->front;
        this->front = this->front->next;
        delete temp;
    }
}

template <class T>
int IndexedList<T>::size() const {
    // Returns size of IndexedList
    return -1;
}

template <class T>
bool IndexedList<T>::is_empty() const {
    // Returns if empty or not
    return false;
}

template <class T>
T IndexedList<T>::getAt(int index) const{
    // Returns element at index
    return T();
}

template <class T>
void IndexedList<T>::addAt(int index, const T& element) {
    // Adds element at an index
}

template <class T>
T IndexedList<T>::removeFirst() {
    // Removes first element in the IndexedList
    return T();
}

template <class T>
T IndexedList<T>::removeAt(int index) {
    // Removes element at specific index
    return T();
}

template <class T>
T IndexedList<T>::removeLast() {
    // Removes last element in the IndexedList
    return T();
}

template <class T>
T IndexedList<T>::first() const {
    // Returns the first element in the IndexedList
    return T();
}

template <class T>
T IndexedList<T>::last() const {
    // Returns the last element in the IndexedList
    return T();
}