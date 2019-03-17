#include "search.h"

int linearSearchIterative(long int arr[], int l, int r, long int value){
	while(l <= r){
		if(arr[l] == value)
			return l;
		else
			l++;
	}

	return -1;
}

int binarySearchIterative(long int arr[], int l, int r, long int value){
	int middle;

	while(l <= r){
		middle = l + ((r - l) / 2);

		if(arr[middle] == value)
			return middle;
		else if(arr[middle] < value)
			l = middle + 1;
		else
			r = middle - 1;
	}

	return -1;
}

int binarySearchRecursive(long int arr[], int l, int r, long int value){
	int middle;

	if(l <= r){
		middle = l + ((r - l) / 2);

		if(arr[middle] == value)
			return middle;
		else if(arr[middle] < value)
			return binarySearchRecursive(arr, middle + 1, r, value);
		else
			return binarySearchRecursive(arr, l, middle - 1, value);
	}

	return -1;
}

int ternarySearchIterative(long int arr[], int l, int r, long int value){
	int leftThird;
	int rightThird;

	while(l <= r){
		leftThird = l + ((r - l) / 3);
		rightThird = l + 2 * ((r - l) / 3);

		if(arr[leftThird] == value)
			return leftThird;
		else if(arr[rightThird] == value)
			return rightThird;
		else if(arr[leftThird] > value)
			r = leftThird - 1;
		else if(arr[rightThird] > value){
			l = leftThird + 1;
			r = rightThird - 1;
		}
		else
			l = rightThird + 1;
	}

	return -1;
}

int ternarySearchRecursive(long int arr[], int l, int r, long int value){
	int leftThird = l + ((r - l) / 3);
	int rightThird = l + 2 * ((r - l) / 3);

	if(l <= r){
		if(arr[leftThird] == value)
			return leftThird;
		else if(arr[rightThird] == value)
			return rightThird;
		else if(arr[leftThird] > value)
			return ternarySearchRecursive(arr, l, leftThird - 1, value);
		else if(arr[rightThird] > value)
			return ternarySearchRecursive(arr, leftThird + 1, rightThird - 1, value);
		else
			return ternarySearchRecursive(arr, rightThird + 1, r, value);
	}

	return -1;
}