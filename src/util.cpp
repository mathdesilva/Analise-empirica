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