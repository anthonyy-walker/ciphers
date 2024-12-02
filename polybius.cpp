/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Names: Jahzarah McIntosh and Anthony Walker
 * uniqnames: jahzarah | skywlkr
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Decrypts or Encrypts a message using polybius.
 */

#include "polybius.h"
#include <cctype>
#include <string>
using namespace std;


// takes the key and adds to alphabet, removing duplicate characters
string mixKey(string key) {
    string mixed;
    mixed = ALNUM;
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < mixed.size(); j++) {
            if (key.at(i) == mixed.at(j)) {
                mixed = mixed.erase(j, 1);
            }
        }
    }
    mixed = key + mixed;
    return mixed;
}

// fills 6x6 grid with alphanumeric characters
void fillGrid(char grid[SIZE][SIZE], string content) {
    int place = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = content.at(place);
            place++;
        }
    }
    return;
}

// finds a character within the grid
string findInGrid(char c, char grid[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == c) {
                return to_string(i) + to_string(j);
            }
        }
    }
    return " ";
}

// Function that encrypts or decrypts a message using the Polybius square
string polybiusSquare(char grid[SIZE][SIZE], string key, 
string original, bool encrypt) {
    key = toUpperCase(key);
    original = toUpperCase(original);

    string mixed = mixKey(key);
    fillGrid(grid, mixed);
    string result;

    if (encrypt) {
        for (int i = 0; i < original.size(); i++) {
            result += findInGrid(original.at(i), grid);
        }
    } else {
        for (int i = 0; i < original.size(); i += 2) {
            if (original.at(i) == ' ') {
                result += ' ';
                i--;
                continue;
            }
            int row = original.at(i) - '0';
            int col = original.at(i + 1) - '0';
            result += grid[row][col];
        }
    }
    return result;
}