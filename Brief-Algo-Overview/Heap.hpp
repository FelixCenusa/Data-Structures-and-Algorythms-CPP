#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
using namespace std;

#include <stdexcept>

template <class T>
class Heap {
private:
    int capacity;
    int nrOfElements;
    T* elements;
    void expand();
public:
    Heap(int initialCapacity = 10);
    ~Heap();
    Heap(const Heap& other) = delete;
    Heap& operator=(const Heap& other) = delete;

    int size() const;
    bool is_empty() const;
    void insert(const T& element);
    T extractMax();
    T getMax() const;
};

#endif

template <class T>
Heap<T>::Heap(int initialCapacity)
{
    this->capacity = initialCapacity;
    this->nrOfElements = 0;
    this->elements = new T[this->capacity];
}

template <class T>
Heap<T>::~Heap()
{
    delete [] this->elements;
}

template <class T>
void Heap<T>::expand()
{
    // Expands the elements array if needed
    T* temp = new T[this->capacity * 2];
    for (int i = 0; i < this->nrOfElements; i++)
    {
        temp[i] = this->elements[i];
    }
    delete [] this->elements;
    this->elements = temp;
    this->capacity *= 2;

}

template <class T>
int Heap<T>::size() const{
    // Return size of HeapList

    return this->nrOfElements;
}

template <class T>
bool Heap<T>::is_empty() const {
    // Returns if empty or now
    return this->nrOfElements == 0;
}

template <class T>
void Heap<T>::insert(const T& element) {
    // Adds elements to Heap
    if (this->nrOfElements == this->capacity)
	{
		this->expand();
	}
    this->elements[this->nrOfElements] = element;
    this->nrOfElements++;
    // # Heapify
    int i = this->nrOfElements - 1;
	while (i > 0)
	{
		int parent = (i - 1) / 2;
		if (this->elements[i] <= this->elements[parent])
			{
			break;
			}
		T temp = this->elements[i];
		this->elements[i] = this->elements[parent];
		this->elements[parent] = temp;
		i = parent;
	}
}

template <class T>
T Heap<T>::extractMax() {
    // # Removes and returns max element
    if (is_empty())
    {
		throw exception("Heap is epty");

    }
    T max = this->elements[0];
    this->elements[0] = this->elements[this->nrOfElements - 1];
    this->nrOfElements--;
    // # Heapify
    int i = 0;
    while (true) // heapify
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < this->nrOfElements && this->elements[left] > this->elements[largest])
            {
            largest = left;
            }
        if (right < this->nrOfElements && this->elements[right] > this->elements[largest])
            {
            largest = right;
            }
        if (largest == i)
            {
            break;
            }
        T temp = this->elements[i];
        this->elements[i] = this->elements[largest];
        this->elements[largest] = temp;
        i = largest;
    }

    return max;
}

template <class T>
T Heap<T>::getMax()const {
    // # Returns max element
    if (is_empty())
    {
        throw exception("Heap is epty");

    }
    return this->elements[0];
}
