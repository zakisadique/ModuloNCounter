/*
 * ModuloNCounter.cpp
 *
 *  Created on: Nov 4, 2023
 *      Author: zakis
 */

/**
 * @file ModuloNCounter.cpp
 * @brief Implementation of the ModuloNCounter class functions.
 */


#include <iostream>
#include "ModuloNCounter.h"
using namespace std;

// constructor
ModuloNCounter::ModuloNCounter(int numDigits, int maxValue){

	if (!checkValidity(maxValue)){ // check if max value is valid
		cout << endl << "End of the test!" << endl;
		exit(1); // exit the program
	} else {
		// assign name enum based on max value
		name = (static_cast<CounterType>(maxValue));
		this -> numDigits = numDigits;
		counter = new ModuloNDigit[numDigits];
		for (int i = 0; i < numDigits; ++i) {
			counter[i].setMaxValue(maxValue - 1);
		}
	}
}

// copy constructor
ModuloNCounter::ModuloNCounter(const ModuloNCounter &copyCounter):
				name(copyCounter.name), numDigits(copyCounter.numDigits) {

	counter = new ModuloNDigit[numDigits];
	for (int i = 0; i < numDigits; ++i) {
		counter[i] = copyCounter.counter[i];
	}
}

// default constructor
ModuloNCounter::ModuloNCounter() : name {INVALID}, numDigits {0}, counter {NULL}
{
}

// overload assignment operator
ModuloNCounter& ModuloNCounter::operator= (const ModuloNCounter& moduloNCounter)
{

	if (this != &moduloNCounter){

		name = moduloNCounter.name;
		numDigits = moduloNCounter.numDigits;

		if (counter){
			delete [] counter;
		}

		counter = new ModuloNDigit[numDigits];
		for (int i = 0; i < numDigits; ++i) {
			counter[i] = moduloNCounter.counter[i];
		}

	}
	return *this;
}


// destructor
ModuloNCounter::~ModuloNCounter() {

	name = INVALID;
	numDigits = 0;
	delete [] counter;
}

// check validity
bool ModuloNCounter::checkValidity(const int &maxValue) const{

	return (maxValue == 2 || maxValue == 8 || maxValue == 10 ||
			maxValue == 16);
}

// print the name of the counter
void ModuloNCounter::printName() const{
	string counterName = "";
	switch (name){
	case 2:
		counterName = "Binary";
		break;

	case 8:
		counterName = "Octal";
		break;

	case 10:
		counterName = "Decimal";
		break;

	case 16:
		counterName = "Hexadecimal";
		break;

	case 0:
		break;
	}

	cout << numDigits << " digit " << counterName << " counter" << endl;
}

// Overload prefix operator
ModuloNCounter& ModuloNCounter::operator++() {
	for (int i = numDigits - 1; i >= 0; --i){
			if (counter[i].counts() == 0){
				break;
			} else {
				// proceed
			}
		}
	return *this;
}

// Overload postfix operator
ModuloNCounter ModuloNCounter::operator++(int dummy){
	ModuloNCounter tempCounter(*this);
	for (int i = numDigits - 1; i >= 0; --i){
		if (counter[i].counts() == 0){
			break;
		} else {
			// proceed
		}
	}
	return tempCounter;
}


// Overload outstream operator
ostream& operator<< (ostream& stream, const ModuloNCounter& moduloCounter){

	for (int i = 0;  i < moduloCounter.numDigits; ++i){
		stream << hex << uppercase << moduloCounter.counter[i].getCount();
	}
	stream << " ";

	return stream;
}


