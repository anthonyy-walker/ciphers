/*
 * vigenere.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

// Function that encrypts or decrypts a message using the Vigenere cipher
string vigenereCipher(string original, string keyword, bool encrypt) {
    keyword = toUpperCase(keyword);
    keyword = removeNonAlphas(keyword);
    int keywordLength = keyword.size();
    int keywordIndex = 0;
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original[i])) {
            int currentKeywordLetter = keyword.at(keywordIndex 
            % keywordLength) - 'A';
            if (encrypt) {
                original[i] = shiftAlphaCharacter(original[i], 
                currentKeywordLetter);
            } else {
                original[i] = shiftAlphaCharacter(original[i], 
                -currentKeywordLetter);
            }
            keywordIndex++;
        }
    }
    return original;
}
