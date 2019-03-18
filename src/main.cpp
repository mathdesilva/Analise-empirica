#include <chrono>
#include <fstream>
#include <iomanip>
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
		std::ofstream outfile ("./data/data.txt");

		//>>>>>>>>>>>>>>>>>>> RUN TESTS <<<<<<<<<<<<<<<<<<
		int curTestCase = 1000;			// current number of elements
		int testsCounter = 0;			// tests counter

		// running each test case
		while(testsCounter < numTests){
			// initializing chrono and setting average
			auto start = std::chrono::steady_clock::now();
			auto end = std::chrono::steady_clock::now();
			auto diff = start - start;

			// running 100 times each test case
			for(int j = 1 ; j <= 100 ; j++){

				start = std::chrono::steady_clock::now();
				// START -------------------------------------------
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
				// END ---------------------------------------------
				end = std::chrono::steady_clock::now();
				diff += ((end - start) - diff)/j;

			}

			// sending average to data file
			std::string str_curTestCase = std::to_string(curTestCase);
			outfile << curTestCase << std::setw(32 - str_curTestCase.size())
				<< std::chrono::duration <double, std::milli> (diff).count()
				<< std:: endl;

			// setting next test case
			if(testsCounter == numTests - 2)
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
				rename("./data/data.txt", "./data/linearData.txt");
				break;
			case '2':
				rename("./data/data.txt", "./data/iterBinaryData.txt");
				break;
			case '3':
				rename("./data/data.txt", "./data/recurBinaryData.txt");
				break;
			case '4':
				rename("./data/data.txt", "./data/iterTernaryData.txt");
				break;
			case '5':
				rename("./data/data.txt", "./data/recurTernaryData.txt");
				break;
			case '6':
				rename("./data/data.txt", "./data/jumpData.txt");
				break;
			case '7':
				rename("./data/data.txt", "./data/fibonacciData.txt");
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