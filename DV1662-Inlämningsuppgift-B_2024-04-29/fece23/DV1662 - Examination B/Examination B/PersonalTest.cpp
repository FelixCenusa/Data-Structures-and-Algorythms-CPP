#include "List.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	List<int> i_list;
	i_list.insertFirst(10);
	i_list.insertFirst(20);
	i_list.insertFirst(30);
	i_list.insertFirst(40);
	i_list.insertLast(69);
	cout << i_list.removeLast() << endl;
	cout << i_list.removeFirst() << endl;
	cout << i_list.removeLast() << endl;
	cout << i_list.removeLast() << endl;
	cout << i_list.removeLast() << endl;





}