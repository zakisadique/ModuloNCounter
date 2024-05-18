/*
 * ModuloNDigit.cpp
 *
 *  Created on: Nov 4, 2023
 *      Author: zakis
 */

/**
 * @file ModuloNDigit.cpp
 * @brief Implementation of the ModuloNDigit class functions.
 */

#include "ModuloNDigit.h"

#include <iostream>

using namespace std;

// constructor
ModuloNDigit::ModuloNDigit(int maxValue) : maxValue (maxValue), currentValue (0)
{}

// increments the counter
int ModuloNDigit::counts() {

	// if the counter has reached max value, reset the current value to 0, else
	// increment the value by 1

	if (currentValue == maxValue){
		currentValue = 0;
		return 1;
	}

	else{
		currentValue++;
		return 0;
	}
}

// gets the current value of the digit counter
int ModuloNDigit::getCount() const {
	return this -> currentValue;
}

// sets the max value of the digit counter
void ModuloNDigit::setMaxValue(int maxValue) {
	this -> maxValue = maxValue;
}

// gets the max value of the digit counter
int ModuloNDigit::getMaxValue()const {
	return this -> maxValue;
}

ModuloNDigit::~ModuloNDigit() {
	// object deleted
}
