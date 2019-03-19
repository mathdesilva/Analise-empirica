#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <new>
#include <stdio.h>
#include <string>

#include "search.h"
#include "util.h"

bool loadingMessage = true;		// set true to show loading messages
long int glob_stepcounter;			// step counter

int main(){
	// testing allocation limit
	std::cout << "Testing allocation limit.\n";
	const int arr_sz = setMemoryLimit();
	if(arr_sz == 0){			// error case
		showErrorMessage(1);
		return 0;
	}

	// allocating array
	std::cout << "Allocating array.\n";
	long int * arr;
	arr = new (std::nothrow) long int [arr_sz];
	if(arr == nullptr){			// error case
		showErrorMessage(1);
		return 0;
	}
	std::cout << "Array with size " << arr_sz << " allocated.\n";

	// putting values in the array
	std::cout << "Putting values.\n";
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


	std::cout << std::endl << ">>>>>>>>>> RUNNING <<<<<<<<<<\n\n";
	//=========== TESTS ============================================
	const int algNumber = str_algorithms.size();		// number of algorithms to be tested
	const int sumIterator = (arr_sz - 1000) / numTests;	// group of elements to sum for each test
	int worstCase = 1;

	// running each algorithm choiced
	for(int i = 0 ; i < algNumber ; i++){
		// open algorithm file to write tests data
		std::ofstream outfiletime ("./data/data1.txt");
		std::ofstream outfilestep ("./data/data2.txt");

		//>>>>>>>>>>>>>>>>>>> RUN TESTS <<<<<<<<<<<<<<<<<<
		int curTestCase = 1000;			// current number of elements
		int testsCounter = 0;			// tests counter

		// initializing chrono and setting average
		auto start = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();
		auto diff = start - start;

		// average steps
		long int averageSteps = 0;

		// Loading message
		if(loadingMessage)
			std::cout << "Loading\n";

		// running each test case
		while(testsCounter < numTests){
			averageSteps = 0;
			diff = start - start;

			// loading message
			if(loadingMessage)
				std::cout << testsCounter + 1 << "th test\n";

			// running 100 times each test case
			for(int j = 1 ; j <= 100 ; j++){
				glob_stepcounter = 0;

				// START -------------------------------------------
				switch(str_algorithms[i]){
					case '1':
						start = std::chrono::steady_clock::now();
						linearSearchIterative(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
					case '2':
						start = std::chrono::steady_clock::now();
						binarySearchIterative(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
					case '3':
						start = std::chrono::steady_clock::now();
						binarySearchRecursive(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
					case '4':
						start = std::chrono::steady_clock::now();
						ternarySearchIterative(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
					case '5':
						start = std::chrono::steady_clock::now();
						ternarySearchRecursive(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
					case '6':
						start = std::chrono::steady_clock::now();
						jumpSearch(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
					case '7':
						start = std::chrono::steady_clock::now();
						fibonacciSearch(arr, 0, curTestCase - 1, worstCase, glob_stepcounter);
						end = std::chrono::steady_clock::now();
						break;
				}			
				// END ---------------------------------------------

				diff += ((end - start) - diff)/j;
				averageSteps += (glob_stepcounter - averageSteps)/j;
			}

			// sending average time to time data file
			std::string str_curTestCase = std::to_string(curTestCase);
			outfiletime << curTestCase << std::setw(32 - str_curTestCase.size())
				<< std::chrono::duration <double, std::milli> (diff).count()
				<< std:: endl;

			// sending average steps to step data file
			outfilestep << curTestCase << std::setw(32 - str_curTestCase.size())
				<< averageSteps << std:: endl;

			// setting next test case
			if(testsCounter == numTests - 2)
				curTestCase = arr_sz;
			else
				curTestCase += sumIterator;

			testsCounter++; 
		}

		//>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<

		// ending loading message
		if(loadingMessage)
			std::cout << std::endl;

		// close algorithm data files
		outfiletime.close();
		outfilestep.close();

		// rename data file
		switch(str_algorithms[i]){
			case '1':
				rename("./data/data1.txt", "./data/linearDataTime.txt");
				rename("./data/data2.txt", "./data/linearDataStep.txt");
				std::cout << ">>> Iterative Linear Search result:" << std::endl;
				break;
			case '2':
				rename("./data/data1.txt", "./data/iterBinaryDataTime.txt");
				rename("./data/data2.txt", "./data/iterBinaryDataStep.txt");
				std::cout << ">>> Iterative Binary Search result:" << std::endl;
				break;
			case '3':
				rename("./data/data1.txt", "./data/recurBinaryDataTime.txt");
				rename("./data/data2.txt", "./data/recurBinaryDataStep.txt");
				std::cout << ">>> Recursive Binary Search result:" << std::endl;
				break;
			case '4':
				rename("./data/data1.txt", "./data/iterTernaryDataTime.txt");
				rename("./data/data2.txt", "./data/iterTernaryDataStep.txt");
				std::cout << ">>> Iterative Ternary Search result:" << std::endl;
				break;
			case '5':
				rename("./data/data1.txt", "./data/recurTernaryDataTime.txt");
				rename("./data/data2.txt", "./data/recurTernaryDataStep.txt");
				std::cout << ">>> Recursive Ternary Search result:" << std::endl;
				break;
			case '6':
				rename("./data/data1.txt", "./data/jumpDataTime.txt");
				rename("./data/data2.txt", "./data/jumpDataStep.txt");
				std::cout << ">>> Jump Search result:" << std::endl;
				break;
			case '7':
				rename("./data/data1.txt", "./data/fibonacciDataTime.txt");
				rename("./data/data2.txt", "./data/fibonacciDataStep.txt");
				std::cout << ">>> Fibonacci Search result:" << std::endl;
				break;
		}

		// show result
		std::cout << "   > Worst case using " << arr_sz << " elements: "
			<< std::chrono::duration <double, std::milli> (diff).count()
			<< " ms\n";
		std::cout << "   > Number of steps to " << arr_sz << " elements: "
			<< averageSteps << std::endl << std::endl;
	}

	//==============================================================

	// deallocating array
	delete[] arr;

	return 0;
}