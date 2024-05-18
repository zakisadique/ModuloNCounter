/*
 * ModuloNDigit.h
 *
 *  Created on: Nov 4, 2023
 *      Author: zakis
 */

/**
 * @file ModuloNDigit.h
 * @brief Definition of the ModuloNDigit class.
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

#include <iostream>
using namespace std;

/**
 * @class ModuloNDigit
 * @brief Represents a digit in a modulo-N counter. The counter counts from 0 to
 	 a given maximum value before getting reset to 0 again.
 */
class ModuloNDigit {

private:

    int maxValue; ///< The maximum value for the single digit counter.
    int currentValue; ///< The current value of the single digit counter.

public:

    /**
     * @brief Default constructor.
     * Initializes maxValue and currentValue to 0.
     */
    ModuloNDigit() : maxValue(0), currentValue(0) {}

    /**
     * @brief Parameterized constructor.
     * Initializes maxValue and currentValue based on the given maxValue.
     * @param maxValue The maximum value for the digit.
     */
    ModuloNDigit(int maxValue);

    /**
     * @brief C/digit.
     * Increments the currentValue by 1 and resets it to 0 if it exceeds
     	 maxValue.
     * @return The current value after counting.
     */
    int counts();

    /**
     * @brief Gets the current value of the digit.
     * @return The current value.
     */
    int getCount() const;

    /**
     * @brief Sets the maximum value for the digit.
     * @param maxValue The maximum value to be set.
     */
    void setMaxValue(int maxValue);

    /**
     * @brief Gets the maximum value of the digit.
     * @return The maximum value.
     */
    int getMaxValue() const;

    /**
     * @brief Destructor for the ModuloNDigit class.
     */
    ~ModuloNDigit();

};

#endif /* MODULONDIGIT_H_ */

