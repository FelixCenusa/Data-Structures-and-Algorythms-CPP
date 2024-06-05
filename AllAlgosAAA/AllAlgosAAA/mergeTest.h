#include <iostream>
using namespace std;
#ifndef MERGE_TEST
#define MERGE_TEST

template <typename T>
void merge(T arr[], int s, int midIndex, int e) {
	int left = s;
	int right = midIndex + 1;
	int index = 0;
	T* temp = new T[e - s + 1];
	while (left <= midIndex && right <= e) 
	{
		if (arr[left] <= arr[right])
		{
			temp[index] = arr[left];
			index++;
			left++;
		}
		else
		{
			temp[index] = arr[right];
			index++;
			right++;

		}
	}
	while (left <= midIndex) {
		temp[index] = arr[left];
		index++;
		left++;
	}
	while (right <= e) {
		temp[index] = arr[right];
		index++;
		right++;
	}
	for (int i = 0; i < (e + 1 - s); i++)
	{
		arr[i + s] = temp[i];

	}
	delete temp;
}

template <typename T>
void mergesort(T arr[], int s, int e) {
	if (s < e)
	{
		int midIndex = (s + e) / 2;
		mergesort(arr, s, midIndex);
		mergesort(arr, midIndex + 1, e);
		merge(arr, s, midIndex, e);

	}
}

template <typename T>
void mergesort(T arr[], int nrOf) {
	mergesort(arr, 0, nrOf - 1);
}





#endif