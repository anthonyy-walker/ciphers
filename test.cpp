#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testShiftAlphaCharacter();
void testToUpperCase();
void testRemoveNonAlphas();
void testCharToInt();
void testRemoveDuplicate();
void testCaesarCipher();
void testVigenereCipher();
void testMixKey();
void testFillGrid();
void testFindInGrid();
void testPolybiusSquare();

void startTests()
{
    testShiftAlphaCharacter();
    testToUpperCase();
    testRemoveNonAlphas();
    testCharToInt();
    testRemoveDuplicate();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();
    return;
}

void testShiftAlphaCharacter()
{
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "(a,0) Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "(b,1) Expected: 'c', Actual: '" << shiftAlphaCharacter('b', 1) << "'" << endl;
    cout << "(z,2) Expected: 'b', Actual: '" << shiftAlphaCharacter('z', 2) << "'" << endl;
    cout << "(Z,10) Expected: 'J', Actual: '" << shiftAlphaCharacter('Z', 10) << "'" << endl;
    cout << "(F,8) Expected: 'N', Actual: '" << shiftAlphaCharacter('F', 8) << "'" << endl;
    cout << "(W, -18) Expected: 'E', Actual: '" << shiftAlphaCharacter('W', -18) << "'" << endl;
    cout << "(A, -3) Expected: 'X', Actual: '" << shiftAlphaCharacter('A', -3) << "'" << endl;
    cout << "(D, -4) Expected: 'Z', Actual: '" << shiftAlphaCharacter('D', -4) << "'" << endl;
    return;
}

void testToUpperCase()
{
    cout << "Testing toUpperCase..." << endl;
    cout << "Test 1: " << (toUpperCase("hello") == "HELLO" ? "Passed" : "Failed") << endl;
    cout << "Test 2: " << (toUpperCase("HeLLo") == "HELLO" ? "Passed" : "Failed") << endl;
    cout << "Test 3: " << (toUpperCase("1234") == "1234" ? "Passed" : "Failed") << endl;
    cout << "Test 4: " << (toUpperCase("!@#") == "!@#" ? "Passed" : "Failed") << endl;
    cout << "Test 5: " << (toUpperCase("TheodorE ROOSEVElt") == "THEODORE ROOSEVELT" ? "Passed" : "Failed") << endl;
    cout << "Test 6: " << (toUpperCase("mIA!!") == "MIA!!" ? "Passed" : "Failed") << endl;
    cout << "Test 7: " << (toUpperCase("Johnothan_Cooper") == "JOHNOTHAN_COOPER" ? "Passed" : "Failed") << endl;
    cout << "Test 8: " << (toUpperCase("S") == "S" ? "Passed" : "Failed") << endl;
    cout << "Test 9: " << (toUpperCase(" ") == " " ? "Passed" : "Failed") << endl;
    cout << "Test 10: " << (toUpperCase("0") == "0" ? "Passed" : "Failed") << endl;
}

void testRemoveNonAlphas()
{
    cout << "Testing removeNonAlphas..." << endl;
    cout << "Test 1: " << (removeNonAlphas("hello123") == "hello" ? "Passed" : "Failed") << endl;
    cout << "Test 2: " << (removeNonAlphas("HeLLo!@#") == "HeLLo" ? "Passed" : "Failed") << endl;
    cout << "Test 3: " << (removeNonAlphas("1234") == "" ? "Passed" : "Failed") << endl;
    cout << "Test 4: " << (removeNonAlphas("!@#") == "" ? "Passed" : "Failed") << endl;
}

void testCharToInt()
{
    cout << "Testing charToInt..." << endl;
    cout << "Test 1: " << (charToInt('5') == 5 ? "Passed" : "Failed") << endl;
    cout << "Test 2: " << (charToInt('0') == 0 ? "Passed" : "Failed") << endl;
    cout << "Test 3: " << (charToInt('9') == 9 ? "Passed" : "Failed") << endl;
    cout << "Test 4: " << (charToInt('3') == 3 ? "Passed" : "Failed") << endl;
    cout << "Test 5: " << (charToInt('8') == 8 ? "Passed" : "Failed") << endl;
}

void testRemoveDuplicate()
{
    cout << "Testing removeDuplicate..." << endl;
    cout << "Test 1: " << (removeDuplicate("HELLO") == "HELO" ? "Passed" : "Failed") << endl;
    cout << "Test 2: " << (removeDuplicate("AAABBBCC") == "ABC" ? "Passed" : "Failed") << endl;
    cout << "Test 3: " << (removeDuplicate("ACB") == "ACB" ? "Passed" : "Failed") << endl;
    cout << "Test 4: " << (removeDuplicate("SCH00L") == "SCH0L" ? "Passed" : "Failed") << endl;
    cout << "Test 5: " << (removeDuplicate("MISSISIPPI") == "MISP" ? "Passed" : "Failed") << endl;
    cout << "Test 6: " << (removeDuplicate("QUANTUMPHYSICS") == "QUANTMPHYSICS" ? "Passed" : "Failed") << endl;
    cout << "Test 7: " << (removeDuplicate("AMAZONPRIME101") == "AMZONPRIE10" ? "Passed" : "Failed") << endl;
    cout << "Test 8: " << (removeDuplicate("C") == "C" ? "Passed" : "Failed") << endl;
}

void testCaesarCipher()
{
    cout << "Testing caesarCipher(): \n";
    cout << "Expected: Cuuj cu qj jxu Tyqw qj 11 f.c., ";
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "Expected: P zvsltusf zdlhy aoha P ht bw av uv nvvk.";
    cout << caesarCipher("I solemnly swear that I am up to no good.", 7, true) << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m.";
    cout << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
}

void testVigenereCipher()
{
    cout << "Testing vigenereCipher" << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m." << endl;
    cout << "Test 2: " << (vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false)) << endl;
    cout << "Expected: Vhq hof ks ktfdqw fdxsa azs cl ks m ccug dmn!";
    cout << "Actual: " << vigenereCipher("The sun is shining today and it is a nice day!", "Foul", true) << endl;
    cout << "Expected: N vuo f ulpfh ntrs ue yvy affnj dsmejfxld.";
    cout << "Test 3: ";
    cout << vigenereCipher("I had a great time at the party yesterday.", "Foul", true) << endl;
    cout << "Expected: Bvue fa C rtwhr yc xz fpify hbp koccnsm ts hbp gowvdolo?!";
    cout << "Test 4: ";
    cout << vigenereCipher("What am I going to do about the fairies in the backyard?!", "Foul", true) << endl;
}

void testMixKey()
{
    cout << "Testing mixKey()" << endl;
    cout << mixKey("POLYBIUS") << endl;
    cout << mixKey("GLOBE") << endl;
    cout << mixKey("ENVY") << endl;
    cout << mixKey("PHYSIC205") << endl;
    cout << mixKey("UMICH28") << endl;
    cout << mixKey("FRESH01") << endl;
}

void testFillGrid()
{
    char grid[SIZE][SIZE] = {};
    cout << "Testing fillGrid()" << endl;
    cout << "Actual: " << endl;
    fillGrid(grid, "The quick brown fox jumps over the j");
    fillGrid(grid, "A journey of a thousand miles begins");
    fillGrid(grid, "All that glitters is not gold, yes s");
    fillGrid(grid, "To be or not to bed that is the ques");
    fillGrid(grid, "Every cloud has a silver lininga yes");
}

void testFindInGrid()
{
    char grid[SIZE][SIZE] = {}; 
    cout << "Testing findInGrid()" << endl;
    cout << "KEY: POLYBIUS | Expected: 21" << endl;
    cout << "Actual: " << findInGrid('G', grid) << endl;
    cout << "KEY: POLYBIUS | Expected: 32" << endl;
    cout << "Actual: " << findInGrid('R', grid) << endl;
    cout << "KEY: POLYBIUS | Expected: 15" << endl;
    cout << "Actual: " << findInGrid('E', grid) << endl;
    cout << "KEY: POLYBIUS | Expected: 42" << endl;
    cout << "Actual: " << findInGrid('0', grid) << endl;
}

void testPolybiusSquare()
{
    char grid[SIZE][SIZE] = {}; 
    cout << "Testing polybiusSquare()" << endl;

    cout << "KEY: 183ECS | Expected: THE GRASSHOPPER LIES HEAVY" << endl;
    cout << "Actual: " << polybiusSquare(grid, "183ECS", "341503 1433100505153031310333 23200305 1503104043", false) << endl;

    cout << "KEY: POLYBIUS | Expected: 15151311 435445 0511 332215 04151133" << endl;
    cout << "Actual: " << polybiusSquare(grid, "POLYBIUS", "EECS 183 IS THE BEST", true) << endl;

    cout << "KEY: 183EECS | Expected: THE GRASSHOPPER LIES HEAVY" << endl;
    cout << "Actual: " << polybiusSquare(grid, "183ECS", "341503 1433100505153031310333 23200305 1503104043", false) << endl;
}