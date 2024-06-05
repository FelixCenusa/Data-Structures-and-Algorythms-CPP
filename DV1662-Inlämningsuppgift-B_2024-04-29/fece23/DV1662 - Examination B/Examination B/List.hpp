#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class List {
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
    List();
    ~List();
    List(const List& other) = delete;
    List& operator=(const List& other) = delete;
    
    int size() const;
    bool is_empty() const;
    void insertFirst(const T& element);
    void insertLast(const T& element);
    T removeFirst();
    T removeLast();
    T getFirst() const ;
    T getLast() const;
};

template<class T>
List<T>::List() : 
    front(nullptr), num_elements(0)
{
}

template <class T>
List<T>::~List()
{
    // Free allocated memory
    //WHILE not empty, remove delete one then elements-- then repeat until empty.
    while (!is_empty())
    {
        removeFirst();
    }
    //worked without but ok
}

template <class T>
int List<T>::size() const {
    // Returns size of List
    return num_elements;
}

template <class T>
bool List<T>::is_empty() const {
    // Returns if empty or not
    return num_elements == 0;
}

template <class T>
void List<T>::insertFirst(const T& element) {
    // Adds element at the beginning of the List
    if (is_empty())
    {
        front = new Node(element);
        num_elements++;
    }
    else
    {
        Node* newNode = new Node(element);
        newNode->next = front;
        front = newNode;
        num_elements++;

    }

}
template <class T>
void List<T>::insertLast(const T& element) {
    // Adds element at the end of the List
    if (is_empty())
    {
        front = new Node(element);
        num_elements++;
    }
    else
    {
        Node* newNode = new Node(element);
        Node* walker = front;
        while (walker->next != nullptr)
        {
            walker = walker->next;
        }
        walker->next = newNode;
        num_elements++;
    }

}
template <class T>
T List<T>::removeFirst() {
    // Removes first element in the List
    if (is_empty())
    {
        
        throw exception("Cant remove First, list is already empty");
    }
    Node* temp = front;
    front = front->next;
    num_elements--;
    // delete temp;

    return temp->data;
}

template <class T>
T List<T>::removeLast() {
    // Removes last element in the List
    if (is_empty())
    {
        
        throw exception("Cant remove Last, list is already empty");
        cout << "why is this printing wtf";
    }
    if (num_elements == 1)
    {
        Node* dataFront = front;
        front->next = nullptr;
        num_elements--;
        return dataFront->data;
    }
    Node* walker = front;
    Node* prevWalk = walker;
    while (walker->next != nullptr)
    {
        prevWalk = walker;
        walker = walker->next;
    }
    prevWalk->next = nullptr;
    num_elements--;
    return walker->data;
}

template <class T>
T List<T>::getFirst() const {
    // Returns the first element in the List
    if (is_empty())
    {
        
        throw exception("Cant get First, list is empty");
    }
    return front->data;
}

template <class T>
T List<T>::getLast() const {
    // Returns the last element in the List
    if (is_empty())
    {
        
        throw exception("Cant get Last, list is empty");
    }
    else
    {
        Node* walker = front;

        while (walker->next != nullptr)
        {
            walker = walker->next;
        }
        return walker->data;
    }
}

#endif