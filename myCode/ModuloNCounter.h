/*
 * ModuloNCounter.h
 *
 *  Created on: Nov 4, 2023
 *      Author: zakis
 */

/**
 * @file ModuloNCounter.h
 * @brief Definition of the ModuloNCounter class and related enumerations.
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

#include "ModuloNDigit.h"
#include <iostream>

/**
 * @enum CounterType
 * @brief Enumeration representing types of counters.
 */
enum CounterType {
    BINARY = 2,         ///<Binary counter.
    OCTAL = 8,          ///< Octal counter.
    DECIMAL = 10,       ///< Decimal counter.
    HEXADECIMAL = 16,   ///< Hexadecimal counter.
    INVALID = 0         ///< Invalid counter type.
};

/**
 * @class ModuloNCounter
 * @brief Represents a modulo-N counter consisting of ModuloNDigit objects.
 */
class ModuloNCounter {
private:
    CounterType name;    ///< Type of the counter (e.g. Binary, Octal, etc).
    int numDigits;       ///< Number of digits in the counter.
    ModuloNDigit* counter; ///< Array of ModuloNDigit objects

public:
    /**
     * @brief Default constructor.
     * Initializes the counter with default values.
     */
    ModuloNCounter();

    /**
     * @brief Parameterized constructor.
     * Initializes the counter with the specified number of digits and
     * maximum value.
     * @param numDigits The number of digits in the counter.
     * @param maxValue The maximum value for each digit in the counter.
     */
    ModuloNCounter(int numDigits, int maxValue);

    /**
     * @brief Copy constructor.
     * Creates a new counter by copying the contents of a given counter.
     * @param counter The counter to be copied.
     */
    ModuloNCounter(const ModuloNCounter& counter);

    /**
     * @brief Destructor.
     * Cleans up resources allocated for the counter.
     */
    ~ModuloNCounter();

    /**
     * @brief Check the validity of the maximum value.
     * Validates whether the specified maximum value is valid for the counter.
     * @param maxValue The maximum value to be checked.
     * @return True if the maximum value is valid, false otherwise.
     */
    bool checkValidity(const int& maxValue) const;

    /**
     * @brief Print the name of the counter type.
     * Prints the name of the counter type on the console.
     */
    void printName() const;

    /**
     * @brief Print the current state of the counter.
     * Prints the current state of the counter on the console.
     */

    ModuloNCounter& operator++();

    /**
     * @brief Postfix increment operator.
     * Increments the counter and returns a copy of the counter before
     * the increment.
     * @param dummy Dummy parameter to distinguish between prefix and
     * postfix operators.
     * @return Copy of the counter before the increment.
     */
    ModuloNCounter operator++(int dummy);

    /**
     * @brief Assignment operator.
     * Assigns the contents of another counter to this counter.
     * @param moduloNCounter The counter to be assigned.
     * @return Reference to the updated counter.
     */
    ModuloNCounter& operator=(const ModuloNCounter& moduloNCounter);

    /**
     * @brief Overloading outstream operator.
     * pushes the current state of the counter to the output stream.
     * @param lhs The output stream.
     * @param counter The counter that is to be output.
     * @return Reference to the output stream.
     */
    friend ostream& operator<<(ostream& lhs, const ModuloNCounter& counter);

};

#endif /* MODULONCOUNTER_H_ */
