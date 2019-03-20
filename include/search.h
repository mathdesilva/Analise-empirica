#ifndef SEARCH_H
#define SEARCH_H

#include <cmath> 	// sqrt()


/*! \brief Linear Search Algorithm
 *
 *  Linear Search code
 */
int linearSearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter); 

/*! \brief Iterative Binary Search Algorithm
 *
 *  Iterative Binary Search code
 */
int binarySearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter);

/*! \brief Recursive Binary Search Algorithm
 *
 *  Recursive Binary Search code
 */
int binarySearchRecursive(long int arr[], int l, int r, long int value, long int &stepcounter);

/*! \brief Iterative Ternary Search Algorithm
 *
 *  Iterative Ternary Search code
 */
int ternarySearchIterative(long int arr[], int l, int r, long int value, long int &stepcounter);

/*! \brief Recursive Ternary Search Algorithm
 *
 *  ternary Search Recursive code
 */
int ternarySearchRecursive(long int arr[], int l, int r, long int value, long int &stepcounter);

/*! \brief Jump Search Algorithm
 *
 *  jump Search code
 */
int jumpSearch(long int arr[], int l, int r, long int value, long int &stepcounter);

/*! \brief Fibonacci Search Algorithm
 *
 *  Fibonacci Search code
 */
int fibonacciSearch(long int arr[], int l, int r, long int value, long int &stepcounter);

#endif