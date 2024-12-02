/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Names: Jahzarah McIntosh and Anthony Walker
 * uniqnames: jahzarah | skywlkr
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * This file decrypts or encrypts a message using caesar.
 */

#include "caesar.h"
#include <iostream>

// This function shifts character 'c' by 'n' places in the alphabet
char shiftAlphaCharacter(char c, int n) {
    n = n % 26;
    if (n >= 0) {
        if (isupper(c)) {
            c = 'A' + ((c - 'A' + n) % 26);
            return c;
        } else if (islower(c)) {
            c = 'a' + ((c - 'a' + n) % 26);
            return c;
        }
    } else if (n < 0) {
        if (isupper(c)) {
            c = 'A' + ((c - 'A' + n) + 26) % 26;
            return c;
        } else if (islower(c)) {
            c = 'a' + ((c - 'a' + n) + 26) % 26;
            return c;
        }
    }
    return c;
}

// Encrypts or decrypts a message using the Caesar cipher
string caesarCipher(string original, int key, bool encrypt) {
    if (encrypt) {
        for (int i = 0; i < original.size(); i++) {
            original.at(i) = shiftAlphaCharacter(original.at(i), key);
        }
    } else {
        key = key * -1;
        for (int j = 0; j < original.size(); j++) {
            original.at(j) = shiftAlphaCharacter(original.at(j), key);
        }
    }
    return original;
}