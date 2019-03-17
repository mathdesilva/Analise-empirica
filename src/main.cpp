#include <iostream>
#include <new>

#include "search.h"

#define MAXN 500000000

int main(){
	// alocando array
	long int * arr;
	arr = new (std::nothrow) long int [MAXN];
	if(arr == nullptr){
		std::cout << "Error: insufficient memory\n";
		return 0;
	}

	// colocando valores no array
	for(int i = 0 ; i < MAXN ; i++)
		arr[i] = i * 2;

	// declarando variavel para testes
	int value1;
	int value2;
	int value3;
	int value4;

	// teste linearSearchIterative
	value1 = linearSearchIterative(arr, 0, MAXN-1, 2000);
	value2 = linearSearchIterative(arr, 0, MAXN-1, 2001);
	value3 = linearSearchIterative(arr, 0, MAXN-1, 0);
	value4 = linearSearchIterative(arr, 0, MAXN-1, (MAXN-1) * 2);
	std::cout << ">>> linearSearchIterative\n";
	std::cout << "Value 1 (1000):" << value1 << std::endl;
	std::cout << "Value 2 (-1):" << value2 << std::endl;
	std::cout << "Value 3 (0):" << value3 << std::endl;
	std::cout << "Value 4 (499999999):" << value4 << std:: endl << std::endl;

	// teste binarySearchIterative
	value1 = binarySearchIterative(arr, 0, MAXN-1, 2000);
	value2 = binarySearchIterative(arr, 0, MAXN-1, 2001);
	value3 = binarySearchIterative(arr, 0, MAXN-1, 0);
	value4 = binarySearchIterative(arr, 0, MAXN-1, (MAXN-1) * 2);
	std::cout << ">>> binarySearchIterative\n";
	std::cout << "Value 1 (1000):" << value1 << std::endl;
	std::cout << "Value 2 (-1):" << value2 << std::endl;
	std::cout << "Value 3 (0):" << value3 << std::endl;
	std::cout << "Value 4 (499999999):" << value4 << std:: endl << std::endl;

	// teste binarySearchRecursive
	value1 = binarySearchRecursive(arr, 0, MAXN-1, 2000);
	value2 = binarySearchRecursive(arr, 0, MAXN-1, 2001);
	value3 = binarySearchRecursive(arr, 0, MAXN-1, 0);
	value4 = binarySearchRecursive(arr, 0, MAXN-1, (MAXN-1) * 2);
	std::cout << ">>> binarySearchRecursive\n";
	std::cout << "Value 1 (1000):" << value1 << std::endl;
	std::cout << "Value 2 (-1):" << value2 << std::endl;
	std::cout << "Value 3 (0):" << value3 << std::endl;
	std::cout << "Value 4 (499999999):" << value4 << std:: endl << std::endl;

	// teste ternarySearchIterative
	value1 = ternarySearchIterative(arr, 0, MAXN-1, 2000);
	value2 = ternarySearchIterative(arr, 0, MAXN-1, 2001);
	value3 = ternarySearchIterative(arr, 0, MAXN-1, 0);
	value4 = ternarySearchIterative(arr, 0, MAXN-1, (MAXN-1) * 2);
	std::cout << ">>> ternarySearchIterative\n";
	std::cout << "Value 1 (1000):" << value1 << std::endl;
	std::cout << "Value 2 (-1):" << value2 << std::endl;
	std::cout << "Value 3 (0):" << value3 << std::endl;
	std::cout << "Value 4 (499999999):" << value4 << std:: endl << std::endl;

	// teste ternarySearchRecursive
	value1 = ternarySearchRecursive(arr, 0, MAXN-1, 2000);
	value2 = ternarySearchRecursive(arr, 0, MAXN-1, 2001);
	value3 = ternarySearchRecursive(arr, 0, MAXN-1, 0);
	value4 = ternarySearchRecursive(arr, 0, MAXN-1, (MAXN-1) * 2);
	std::cout << ">>> ternarySearchRecursive\n";
	std::cout << "Value 1 (1000):" << value1 << std::endl;
	std::cout << "Value 2 (-1):" << value2 << std::endl;
	std::cout << "Value 3 (0):" << value3 << std::endl;
	std::cout << "Value 4 (499999999):" << value4 << std:: endl << std::endl;

	delete[] arr;


	return 0;
}