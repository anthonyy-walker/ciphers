/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Names: Jahzarah McIntosh and Anthony Walker
 * uniqnames: jahzarah | skywlkr
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>

// Function that converts the alphabetical characters in a string to uppercase
string toUpperCase(string original) {
    for (int i = 0; i < original.length(); ++i) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            original[i] = toupper(original[i]);
        }
    }
    return original;
}

// Function that removes all non alophabetic characters from a string
string removeNonAlphas(string original) {
    string result;
    for (int i = 0; i < original.length(); ++i) {
        if (isalpha(original[i])) {
            result += original[i];
        }
    }
    return result;
}

int charToInt(char original) {
    if (original >= '0' && original <= '9') {
        return original - '0';
    }
    return -1;
}

// Function that removes duplicate characters from a string
string removeDuplicate(string original) {
    string result;
    for (int i = 0; i < original.length(); ++i) {
        if (result.find(original[i]) == -1) {
            result += original[i];
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
