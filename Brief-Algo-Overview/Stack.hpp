#ifndef STACK_H
#define STACK_H

#include "List.hpp"
#include <stdexcept>

template <class T>
class Stack
{
private:
	// To be filled by student
	List <T> ListHere;
	// int nrOf;
public:
	Stack();
	virtual ~Stack() = default;
	Stack(const Stack& other) = delete;
	Stack& operator=(const Stack& other) = delete;
	
	void push(const T& element);
	T pop();
	T peek() const;
	bool is_empty() const;
	int size() const;
};

template <class T>
Stack<T>::Stack()
{
	// nrOf = 0; have to nrof ++ and -- in pop and push but we dont need it since we have num_elements.
}

template <class T>
void Stack<T>::push(const T& element)
{
	ListHere.insertFirst(element);
}

template <class T>
T Stack<T>::pop()
{
	return ListHere.removeFirst();
}

template <class T>
T Stack<T>::peek() const
{
	return ListHere.getFirst();
}

template <class T>
bool Stack<T>::is_empty() const
{
	return ListHere.is_empty();
}

template <class T>
int Stack<T>::size() const
{
	return ListHere.size();
}

#endif