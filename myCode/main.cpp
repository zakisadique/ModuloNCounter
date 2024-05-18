/*! \mainpage Modulo N Counter Implementation
 *
 * The implemented modulo-N counter is a digital counter that takes two
 * parameters, namely, number of digits, and the counter type.
 *
 * The counter type is limited to binary, octal, decimal, and hexadecimal.
 * If the user enters a type other than the ones listed above, an error message
 * is shown and the program terminates.
 *
 * If the parameters provided are within the range, the programs counts from 0
 * to N-1, before resetting to 0 again.
 */



/**
 * @file main.cpp
 * @brief Entry point for the ModuloNCounter application.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "ModuloNCounter.h"

using namespace std;

/**
 * @brief Entry point for the ModuloNCounter application.
 * Prompts the user for counter parameters, creates counters, and
 	 demonstrates their behavior.
 * @return Exit code.
 */
int main()
{
    cout << "Please enter the parameters of your counter:" << endl;

    // Input number of digits
    cout << "Number of digits: " << endl;
    int numDigits = 0;
    cin >> numDigits;

    // Input counter type
    cout << "Type (2/8/10/16): " << endl;
    int counterType = 0;
    cin >> counterType;

    // Create and demonstrate the counter with prefix increment
    ModuloNCounter counter(numDigits, counterType);
    counter.printName();
    for (int i = 1; i < pow(counterType, numDigits) + 3; ++i)
    {
        cout << ++counter;

        // Formatting output based on counter type
        if (counterType == 8 || counterType == 10 || counterType == 16)
        {
            if (i % counterType == 0)
            {
                cout << endl;
            }
        }
        else if (counterType == 2)
        {
            if (i % 16 == 0)
            {
                cout << endl;
            }
        }
    }
    cout << endl << endl;

    // Create and demonstrate the counter with postfix increment
    ModuloNCounter counter2(numDigits, counterType);
    counter.printName();
    for (int i = 1; i < pow(counterType, numDigits) + 3; ++i)
    {
        cout << counter2++;

        // Formatting output based on counter type
        if (counterType == 8 || counterType == 10 || counterType == 16)
        {
            if (i % counterType == 0)
            {
                cout << endl;
            }
        }
        else if (counterType == 2)
        {
            if (i % 16 == 0)
            {
                cout << endl;
            }
        }
    }

    return 0;
}

