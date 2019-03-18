#include <chrono>
#include <fstream>
#include <iostream>
#include <new>
#include <stdio.h>
#include <string>

#include "search.h"
#include "util.h"

int main(){
	// testing allocation limit
	const int arr_sz = setMemoryLimit();
	if(arr_sz == 0){			// error case
		showErrorMessage(1);
		return 0;
	}

	// allocating array
	long int * arr;
	arr = new (std::nothrow) long int [arr_sz];
	if(arr == nullptr){			// error case
		showErrorMessage(1);
		return 0;
	}
	std::cout << "Array with size " << arr_sz << " allocated.\n";

	// putting values in the array
	for(int i = 0 ; i < arr_sz ; i++)
		arr[i] = i * 2;

	// getting number of tests
	const int numTests = numberOfTestsMenu();
	if(numTests == 0){			// error case
		showErrorMessage(2);
		delete[] arr;
		return 0;
	}

	// getting algorithm choices
	std::string str_algorithms = setAlgorithmsMenu();
	if(str_algorithms == "0"){		// error case
		showErrorMessage(2);
		delete[] arr;
		return 0;
	}

	//=========== TESTS ============================================
	const int algNumber = str_algorithms.size();		// number of algorithms to be tested
	const int sumIterator = (arr_sz - 1000) / numTests;	// group of elements to sum for each test
	int worstCase = 1;
	// running each algorithm choiced
	for(int i = 0 ; i < algNumber ; i++){
		// open algorithm file to write tests data
		std::ofstream outfile ("data.txt");

		//>>>>>>>>>>>>>>>>>>> RUN TESTS <<<<<<<<<<<<<<<<<<
		int curTestCase = 1000;			// current number of elements
		int testsCounter = 0;			// tests counter

		// running each test case
		while(testsCounter < numTests){

			// running 100 times each test case
			for(int j = 0 ; j < 100 ; j++){

				switch(str_algorithms[i]){
					case '1':
						linearSearchIterative(arr, 0, curTestCase - 1, worstCase);
						break;
					case '2':
						binarySearchIterative(arr, 0, curTestCase - 1, worstCase);
						break;
					case '3':
						binarySearchRecursive(arr, 0, curTestCase - 1, worstCase);
						break;
					case '4':
						ternarySearchIterative(arr, 0, curTestCase - 1, worstCase);
						break;
					case '5':
						ternarySearchRecursive(arr, 0, curTestCase - 1, worstCase);
						break;
					case '6':
						jumpSearch(arr, 0, curTestCase - 1, worstCase);
						break;
					case '7':
						fibonacciSearch(arr, 0, curTestCase - 1, worstCase);
						break;
				}			

			}

			// setting next test case
			if(testsCounter == numTests - 1)
				curTestCase = arr_sz;
			else
				curTestCase += sumIterator;

			testsCounter++; 
		}

		//>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<

		// close algorithm data file
		outfile.close();

		// rename data file
		switch(str_algorithms[i]){
			case '1':
				rename("data.txt", "linearData.txt");
				break;
			case '2':
				rename("data.txt", "iterBinaryData.txt");
				break;
			case '3':
				rename("data.txt", "recurBinaryData.txt");
				break;
			case '4':
				rename("data.txt", "iterTernaryData.txt");
				break;
			case '5':
				rename("data.txt", "recurTernaryData.txt");
				break;
			case '6':
				rename("data.txt", "jumpData.txt");
				break;
			case '7':
				rename("data.txt", "fibonacciData.txt");
				break;
		}
	}

	//==============================================================

	// test
	std::cout << numTests << std::endl;
	std::cout << str_algorithms << std::endl;


	// deallocating array
	delete[] arr;

	return 0;
}