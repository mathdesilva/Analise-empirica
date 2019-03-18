#ifndef SEARCH_H
#define SEARCH_H

#include <cmath>

int linearSearchIterative(long int arr[], int l, int r, long int value); 

int binarySearchIterative(long int arr[], int l, int r, long int value);

int binarySearchRecursive(long int arr[], int l, int r, long int value);

int ternarySearchIterative(long int arr[], int l, int r, long int value);

int ternarySearchRecursive(long int arr[], int l, int r, long int value);

int jumpSearch(long int arr[], int l, int r, long int value);

#endif