/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Names: Jahzarah McIntosh, Anthony Walker
 * Uniqnames: jahzarah | skywlkr
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Decrypt or encrypt a message using caesar, vígenere, or polybius!
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// isValidKey checks for polybius 
bool isValidKey(string key) {
    // making sure key is uppercase and has no duplicates
    key = toUpperCase(key);
    key = removeDuplicate(key);

    // if statement checks if key is valid in different ways. 
    if (key.empty()) {
        return false;
    }

    for (int i = 0; i < key.size(); i++) {
        if (!isalnum(key.at(i))) {
            return false;
        }
    }

    for (int i = 0; i < key.size(); i++) {
        for (int j = i + 1; j < key.size(); j++)
        {
            if (key.at(i) == key.at(j))
            {
                return false;
            }
        }
    }
    return true;
}

// ciphers function allows user to choose between caesar, vigenere, or polybius
void ciphers() {

    // Ask user for cipher (Caesar, Vigenere, or Polybius)
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    string cipher;
    cin >> cipher;
    cipher = toUpperCase(cipher);

    if (cipher != "CAESAR" && cipher != "C" && cipher != "VIGENERE" 
    && cipher != "V" && cipher != "POLYBIUS" && cipher != "P") {
        cout << "Invalid cipher!" << endl;
        return;
    }

    // Ask user to encrypt or decrypt
    cout << "Encrypt or decrypt: ";
    string encrypt;
    cin >> encrypt;
    encrypt = toUpperCase(encrypt);

    if (encrypt != "ENCRYPT" && encrypt != "E" && encrypt 
    != "DECRYPT" && encrypt != "D") {
        cout << "Invalid mode!" << endl;
        return;
    }

    // Get message from user
    cout << "Enter a message: ";
    string message;
    cin.get();
    getline(cin, message);

    if (cipher == "POLYBIUS" || cipher == "P") {
        for (int i = 0; i < message.size(); i++) {
            if (!isalnum(message.at(i)) && message.at(i) != ' ') {
                cout << "Invalid message!" << endl;
                return;
            }
        }
    }

    // get key or keyword from user
    cout << "What is your key: ";
    string key;
    getline(cin, key);

    // Encrypt or decrypt message using selected cipher and key(word)
    if (encrypt == "ENCRYPT" || encrypt == "E") {
        bool ifEncrypt = true;
        int integerKey = 0;
        if (cipher == "CAESAR" || cipher == "C") {
            for (int i = 0; i < key.size(); i++) {
                if (!isdigit(key.at(i))) {
                    cout << "Invalid key!" << endl;
                    return;
                }
            }

            for (int j = 0; j < key.size(); j++) {
                integerKey = integerKey * 10 + charToInt(key.at(j));
            }
            cout << "The encrypted message is: ";
            cout << caesarCipher(message, integerKey, ifEncrypt);
            cout << endl;
        }
        else if (cipher == "VIGENERE" || cipher == "V") {
            key = toUpperCase(key);
            key = removeNonAlphas(key);
            if (key.empty()) {
                cout << "Invalid key!" << endl;
                return;
            }
            cout << "The encrypted message is: " << 
            vigenereCipher(message, key, ifEncrypt);
            cout << endl;
        }
        else if (cipher == "POLYBIUS" || cipher == "P") {
            char grid[SIZE][SIZE];
            key = toUpperCase(key);
            message = toUpperCase(message);
            key = removeDuplicate(key);
            if (!isValidKey(key)) {
                cout << "Invalid key!" << endl;
                return;
            }
            cout << "The encrypted message is: " << 
            polybiusSquare(grid, key, message, ifEncrypt);
            cout << endl;
        }
    }

    else if (encrypt == "DECRYPT" || encrypt == "D") {

        bool ifEncrypt = false;

        if (cipher == "CAESAR" || cipher == "C") {
            int integerKey = 0;
            for (int i = 0; i < key.size(); i++) {
                if (!isdigit(key.at(i))) {
                    cout << "Invalid key!" << endl;
                    return;
                }
            }

            for (int j = 0; j < key.size(); j++) {
                integerKey = integerKey * 10 + charToInt(key.at(j));
            }
            cout << "The decrypted message is: " << 
            caesarCipher(message, integerKey, ifEncrypt) << endl;
        }
        else if (cipher == "VIGENERE" || cipher == "V") {
            key = toUpperCase(key);
            key = removeNonAlphas(key);
            if (key.empty()) {
                cout << "Invalid key!" << endl;
                return;
            }
            cout << "The decrypted message is: " << 
            vigenereCipher(message, key, ifEncrypt) << endl;
        }
        else if (cipher == "POLYBIUS" || cipher == "P") {
            key = toUpperCase(key);
            message = toUpperCase(message);
            key = removeDuplicate(key);
            char grid[SIZE][SIZE];
            if (!isValidKey(key)) {
                cout << "Invalid key!" << endl;
                return;
            }
            cout << "The decrypted message is: " << 
            polybiusSquare(grid, key, message, ifEncrypt) << endl;
        }
    }
}
