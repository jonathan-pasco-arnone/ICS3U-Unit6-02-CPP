// Copyright (c) 2020 Jonathan Pasco-Arnone all rights reserved
//
// Created by Jonathan Pasco-Arnone
// Created on January 2021
// This program finds the greatest number in a list of random numbers

#include <iostream>
#include <array>
#include <random>

template<size_t N>  // allows the program to pass an array into a function
int greatestFinder(std::array<int, N> numbers) {
    // This function finds the greatest number in a list of random numbers

    int previousGreatestNumber = 0;

    for (int loopCounter = 0; loopCounter < 10; loopCounter++) {
        if (previousGreatestNumber < numbers[loopCounter]) {
            previousGreatestNumber = numbers[loopCounter];
        }
    }
    return previousGreatestNumber;
}

main() {
    // This function generates 10 random numbers and displays them

    // an array containing int's that has 10 different values
    std::array<int, 10> numbers;
    int aSingleRandomNumber;
    int greatestNumber;

    std::cout << "" << std::endl;
    std::cout << "The following is 10 randomly generated numbers"
          " stored in the same variable." << std::endl;
    std::cout << "" << std::endl;

    for (int loopCounter = 0; loopCounter < 10; loopCounter++) {
        // Random number code
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(0, 100);  // [0, 100]
        aSingleRandomNumber = idist(rgen);

        numbers[loopCounter] = aSingleRandomNumber;
    }
    for (int loopCounter = 0; loopCounter < 10; loopCounter++) {
        std::cout << "Random number" << loopCounter + 1 << ": "
              << numbers[loopCounter] << std::endl;
    }

    greatestNumber = greatestFinder(numbers);

    std::cout << "" << std::endl;
    std::cout << "The highest one is " << greatestNumber << std::endl;
    std::cout << "" << std::endl;
}
