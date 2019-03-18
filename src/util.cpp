#include "util.h"

int setMemoryLimit(void){
	int curvalue = 100000000; 
	long int * arr;

	while(true){
		arr = new (std::nothrow) long int [curvalue];
		if(arr == nullptr)
			return curvalue - 100000000;
		if(curvalue == 500000000){
			delete[] arr;
			return curvalue;
		}

		delete[] arr;
		curvalue += 100000000;
	}

	return 0;
}

void showErrorMessage(int number){
	switch(number){
		case 1:
			std::cout << "error: insufficient memory.\n";
			break;
		case 2:
			std::cout << "error: invalid value.\n";
			break;
	}
}

int numberOfTestsMenu(void){
	std::string value;
	int intValue;
	int str_sz;

	// getting value
	std::cout << ">>> Set the number of tests [30:100]: ";
	getline(std::cin, value);

	// cleaning value
	str_sz = value.size();
	for(int i = 0 ; i < str_sz ; i++)
		if(value[i] < '0' or value[i] > '9')
			return 0;
	intValue = stoi(value);
	if(intValue > 100 or intValue < 30)
		return 0;
	
	// returning clean int value
	return intValue; 
}

std::string setAlgorithmsMenu(void){
	// showing menu
	std::cout << ">>> algorithms <<<\n";
	std::cout << "  1. Iterative Linear Search\n";
	std::cout << "  2. Iterative Binary Search\n";
	std::cout << "  3. Recursive Binary Search\n";
	std::cout << "  4. Iterative Ternary Search\n";
	std::cout << "  5. Recursive Ternary Search\n";
	std::cout << "  6. Jump Search\n";
	std::cout << "  7. Fibonacci Search\n";
	std::cout << ">>> Set the algorithms index: ";

	// getting value
	std::string value;
	getline(std::cin, value);

	// cleaning value
	std::string cleanValue = "";
	int str_sz = value.size();
	int algFreqList[8] = {0};
	for(int i = 0 ; i < str_sz ; i++){		// removing spaces and repeated values
		if(value[i] >= '1' and value[i] <= '7'){
			int ind = value[i] - 48;
			if(algFreqList[ind] == 0){
				algFreqList[ind]++;
				cleanValue += value[i];
			}
		}
		else if(value[i] != ' ')
			return "0";
	}

	// returning clean std::string value
	return cleanValue;
}