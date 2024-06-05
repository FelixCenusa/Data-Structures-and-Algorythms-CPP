//#include <utility> doesnt work
const bool SELECTION_IMPLEMENTED = true;
const bool INSERTION_IMPLEMENTED = false;

template<typename T> 
int binarySearch(T arr[], int nrOf, T elem)
{
	int start = 0;
	int end = nrOf - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == elem)
		{
			return mid;
		}
		if (arr[mid] > elem)
		{
			end = mid - 1;
		}
		if (arr[mid] < elem)
		{
			start = mid + 1;
		}

	}
	return -1;
}

template<typename T> 
void insertionSort(T arr[], int nrOf)
{
	
}

template<typename T> 
void selectionSort(T arr[], int nrOf)
{
	for (int i = 0; i < nrOf - 1; i++) //remove -1 if too fast
	{
		int smallestIndex = i;
		for (int j = i + 1; j < nrOf; j++)
		{
			if (arr[smallestIndex] > arr[j])
			{
				smallestIndex = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[smallestIndex];
		arr[smallestIndex] = temp;
		//swap(arr[i], arr[smallestIndex]); utility doesnt work so i did it manually above.
	}
} 

template<typename T> 
void merge(T arr[], int startIndex, int midIndex, int endIndex) // who wrote this didnt even delete the heap but it works
{
	int leftNrOf = midIndex-startIndex+1;
	int rightNrOf = endIndex-midIndex;
	T* left = new T[leftNrOf];
	T* right = new T[rightNrOf];

	for(int i = 0; i < leftNrOf; ++i)
		left[i] = arr[startIndex+i];
	for(int i = 0; i < rightNrOf; ++i)
		right[i] = arr[midIndex+1+i];

	int i=startIndex,j=0,k=0;
	while(j < leftNrOf && k < rightNrOf)
	{
		if(left[j] <= right[k])
		{
			arr[i] = left[j];
			++j;
		}
		else
		{
			arr[i] = right[k];
			++k;
		}
		++i;
	}
	while(j < leftNrOf)
	{
		arr[i] = left[j];
		++j;
		++i;
	}
	while(k < rightNrOf)
	{
		arr[i] = right[k];
		++k;
		++i;
	}
} 

template<typename T>
void mergeSortRecursive(T arr[], int startIndex, int endIndex) // but merge is recursive lol
{
	if (startIndex < endIndex)
	{
		int midIndex = (startIndex + endIndex) / 2;
		mergeSortRecursive(arr, startIndex,midIndex);
		mergeSortRecursive(arr,midIndex+1,endIndex);
		merge(arr, startIndex, midIndex, endIndex);
	}
}

template<typename T>
void mergeSort(T arr[], int nrOf)
{
	mergeSortRecursive(arr, 0, nrOf - 1);
}