//#include "AllAtOnce.h"
#include "mergeTest.h"
#include <iostream>
using namespace std;
int main() {
	int arr[] = { 10,20,30,73,26,84,26,84,26,85,7 };
	mergesort(arr, 11);
	for (int i = 0; i < 11; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}