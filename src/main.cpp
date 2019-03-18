#include <iostream>
#include <new>

#include "search.h"
#include "util.h"

int main(){
	const int limitsize = setMemoryLimit();

	// alocando array
	long int * arr;
	arr = new (std::nothrow) long int [limitsize];
	if(arr == nullptr){
		std::cout << "Error: insufficient memory\n";
		return 0;
	}

	// colocando valores no array
	for(int i = 0 ; i < limitsize ; i++)
		arr[i] = i * 2;


	delete[] arr;


	return 0;
}