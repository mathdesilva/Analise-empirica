#include "search.h"


int linearSearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter){

	while(l <= r){
		stepcounter++;

		if(arr[l] == value)
			return l;
		else
			l++;
	}

	return -1;
}

int binarySearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter){
	int middle;

	while(l <= r){
		stepcounter++;

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

int binarySearchRecursive(long int arr[], int l, int r, long int value, long int &stepcounter){
	stepcounter++;

	int middle;

	if(l <= r){
		middle = l + ((r - l) / 2);

		if(arr[middle] == value)
			return middle;
		else if(arr[middle] < value)
			return binarySearchRecursive(arr, middle + 1, r, value, stepcounter);
		else
			return binarySearchRecursive(arr, l, middle - 1, value, stepcounter);
	}

	return -1;
}

int ternarySearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter){
	int leftThird;
	int rightThird;

	while(l <= r){
		stepcounter++;

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

int ternarySearchRecursive(long int arr[], int l, int r, long int value, long int &stepcounter){
	stepcounter++;

	int leftThird = l + ((r - l) / 3);
	int rightThird = l + 2 * ((r - l) / 3);

	if(l <= r){
		if(arr[leftThird] == value)
			return leftThird;
		else if(arr[rightThird] == value)
			return rightThird;
		else if(arr[leftThird] > value)
			return ternarySearchRecursive(arr, l, leftThird - 1, value, stepcounter);
		else if(arr[rightThird] > value)
			return ternarySearchRecursive(arr, leftThird + 1, rightThird - 1, value, stepcounter);
		else
			return ternarySearchRecursive(arr, rightThird + 1, r, value, stepcounter);
	}

	return -1;
}

int jumpSearch(long int arr[], int l, int r, long int value, long int &stepcounter){
	int size_arr = r - l;
	int jumpgroup = sqrt(size_arr);
	int rightgroup = l + jumpgroup;

	while(rightgroup <= r){
		stepcounter++;

		if(arr[rightgroup] == value)
			return rightgroup;
		else if(arr[rightgroup] > value)
			return linearSearchIterative(arr, l, rightgroup - 1, value, stepcounter);
		else{
			l = rightgroup + 1;
			rightgroup += rightgroup;
		}
	}

	return linearSearchIterative(arr, l, r, value, stepcounter);
}

int fibonacciSearch(long int arr[], int l, int r, long int value, long int &stepcounter){
	stepcounter++;

	int size_arr = r - l;

	// mapping fibonacci numbers
	int fib1 = 0;
	int fib2 = 1;
	int fib3 = 1;

	while(fib3 < size_arr){
		fib1 = fib2;
		fib2 = fib3;
		fib3 = fib1 + fib2;
	}

	// searching
	if(l <= r){
		if(arr[l + fib1] == value)
			return l + fib1;
		else if(arr[l + fib1] > value)
			return fibonacciSearch(arr, l, l + fib1 - 1, value, stepcounter);
		else
			return fibonacciSearch(arr, l + fib1 + 1, r, value, stepcounter);
	}

	return -1;
}