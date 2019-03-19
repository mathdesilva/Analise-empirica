#ifndef SEARCH_H
#define SEARCH_H

#include <cmath> 	// sqrt()

int linearSearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter); 

int binarySearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter);

int binarySearchRecursive(long int arr[], int l, int r, long int value, long int &stepcounter);

int ternarySearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter);

int ternarySearchRecursive(long int arr[], int l, int r, long int value, long int &stepcounter);

int jumpSearch(long int arr[], int l, int r, long int value, long int &stepcounter);

int fibonacciSearch(long int arr[], int l, int r, long int value, long int &stepcounter);

#endif