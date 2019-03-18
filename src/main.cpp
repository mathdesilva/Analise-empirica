#include <iostream>
#include <new>
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
	std::string algorithms = setAlgorithmsMenu();
	if(algorithms == "0"){		// error case
		showErrorMessage(2);
		delete[] arr;
		return 0;
	}

	// test
	std::cout << numTests << std::endl;
	std::cout << algorithms << std::endl;


	// deallocating array
	delete[] arr;

	return 0;
}