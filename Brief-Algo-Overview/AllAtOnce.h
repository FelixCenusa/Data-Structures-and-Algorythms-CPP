#include <utility>
#include <iostream>
#include <string>

using namespace std;

#ifndef LAB_A_H
#define LAB_A_H

template <typename T>
void insertionSort(T arr[], int nrOf)
{
	int index;
	for (int i = 1; i < nrOf; i++)
	{
		T element = arr[i];
		index = i - 1;
		while (index >= 0 && element < arr[index])
		{
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = element;
	}
}

template <typename T>
void selectionSort(T arr[], int nrOf)
{

	for (int j = 0; j < nrOf - 1; j++)
	{
		int minIndex = j;
		for (int i = j + 1; i < nrOf; i++)
		{
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
		}
			std::swap(arr[j], arr[minIndex]);

	}

}

template <typename T>
int linearSearch(T arr[], int nrOf, T toFind)
{
	for (int i = 0; i < nrOf; i++)
	{
		if (arr[i] == toFind)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
int binarySearch(T arr[], int nrOf, T toFind)
{

	int min = 0;
	int max = nrOf - 1;

	while (min <= max)
	{
		int indexOfMid = (max + min) / 2;

		if (arr[indexOfMid] == toFind)
		{
			return indexOfMid;
		}
		else if (arr[indexOfMid] < toFind)
		{
			min = indexOfMid + 1;
		}
		else
		{
			max = indexOfMid - 1;
		}
	}
	return -1;
}

template <typename T>
int linearSearchRecursive(T arr[], int size, T toFind)
{
	if (size == 0) {
		return -1;
	}

	else if (arr[size - 1] == toFind) {
		return size - 1;
	}
	else {
		return linearSearchRecursive(arr, size - 1, toFind);
	}

}

template <typename T>
int binarySearchRec(T arr[], int startIndex, int endIndex, T toFind)
{
	// for you to implement
	return 0; // not correct return value
}

template <typename T>
void insertionSortWithBinarySearch(T arr[], int nrOf)
{
	// for you to implement
}







// Du behover skapa egna funktionsmallar for bl.a de algoritmer
// som ar rekursiva och som anropas fron de stommar till 
// funktionsmallar som finns nedan.

template <typename T>
void printArr(T arr, int fromIndex, int toIndex) {
	for (int i = fromIndex; i < toIndex; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void merge(T arr[], int startIndex, int midIndex, int endIndex)
{
	int left = startIndex;
	int right = midIndex + 1;
	int index = 0;
	T* temp = new T[endIndex - startIndex + 1];
	while (left <= midIndex && right <= endIndex)
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
	while (left <= midIndex)
	{
		temp[index] = arr[left];
		index++;
		left++;
	}
	while (right <= endIndex)
	{
		temp[index] = arr[right];
		index++;
		right++;
	}
	for (int i = 0; i < (endIndex + 1 - startIndex); i++)
	{
		arr[i + startIndex] = temp[i];
	}
	delete temp;
}

template <typename T>	
void mergeSort(T arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int midIndex = (endIndex + startIndex) / 2;
		mergeSort(arr, startIndex, midIndex);
		mergeSort(arr, midIndex + 1, endIndex);
		merge(arr, startIndex, midIndex, endIndex);
	}
}
template <typename T>
void mergeSort(T arr[], int nrOf)
{
	mergeSort(arr, 0, nrOf - 1);
}


template <typename T>
int HoaresPartition(T arr[], int startIndex, int endIndex)
{
	T pivot = arr[endIndex];
	int index = startIndex - 1;

	for (int i = startIndex; i < endIndex; i++)
	{
		if (arr[i] <= pivot)
		{
			index++;
			std::swap(arr[i], arr[index]);

		}
	}
	std::swap(arr[endIndex], arr[index + 1]);

	return index + 1;
}
template <typename T>
void quickSort(T arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int pivotIndex = HoaresPartition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, endIndex);
	}
}
template <typename T>
void quickSort(T arr[], int nrOf)
{
	quickSort(arr, 0, nrOf - 1);
}


template <typename T>
void heapify(T arr[], int nrOf, int startIndex)
{
	int indexOfLargest = startIndex;
	int indexOfLeftChild = startIndex * 2 + 1;
	int indexOfRightCild = startIndex * 2 + 2;

	if (indexOfLeftChild < nrOf && arr[indexOfLargest] < arr[indexOfLeftChild])
	{
		indexOfLargest = indexOfLeftChild;
	}
	if (indexOfRightCild < nrOf && arr[indexOfLargest] < arr[indexOfRightCild])
	{
		indexOfLargest = indexOfRightCild;
	}

	if (indexOfLargest != startIndex)
	{
		std::swap(arr[startIndex], arr[indexOfLargest]);
		heapify(arr, nrOf, indexOfLargest);
	}
}

template <typename T>
void heapSort(T arr[], int nrOf)
{
	for (int i = (nrOf / 2) - 1; i >= 0; i--)
	{
		heapify(arr, nrOf, i);
	}
	for (int i = nrOf - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}







#endif

