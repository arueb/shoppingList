/*********************************************************************
 ** Program name: iVal.hpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the interface file for a collection of
    input validation functions.  Functionality includes testing whether
    an input is a valid integer, getting a valid integer from the user
    with an optional minimum and/or maximum values.  There is also 
    a funtion that returns a lowercase version of an input string.  
 *********************************************************************/

#ifndef iVal_hpp
#define iVal_hpp

#include <string>
#include <iostream>
using std::string;

int getValidInt(int min, int max); // get valid int with in min/max range
int getValidIntMin(int min); // get valid int >= min value
int getValidInt(); // get any valid int
bool isInt(std::string input); //returns true if input is valid
string strToLower(string); //returns a lowercase version of the input string
#endif /* iVal_hpp */
