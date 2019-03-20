#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <new>
#include <string>

/*! \brief Test Memory Limit
 *
 *  Try to alloc 100.000.000 to 500.000.000 long ints and return the max of the successful allocations
 */
int setMemoryLimit(void);

/*! \brief Show a message error
 *
 *  send a number and show in terminal a message error of the namber
 */
void showErrorMessage(int number);

/*! \brief Number of tests menu
 *
 *  Show a menu, get input of number of tests, clean input and return an int
 */
int numberOfTestsMenu(void);

/*! \brief Set algorithm menu
 *
 *  Show a menu, get input of algorithms to be tested and return a string with each
 *  char is a algorithm number.
 */
std::string setAlgorithmsMenu(void);

#endif