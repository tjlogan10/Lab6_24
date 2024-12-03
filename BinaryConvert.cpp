#include "BinaryConvert.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

BConvert::BConvert() {}; //constructor

BConvert::~BConvert() {} //destructor

void BConvert::printResult(int decimal, string binaryNumber){ //Prints the binary number and the decimal result
    cout << setw(30) << left << binaryNumber << setw(15) << right << decimal << endl;
}
// Post condition: outputs binary and decimal equivalent

// Pre condition: takes a character as an input
bool BConvert::validBinary(char c){ // Checks if the binary is a valid binary digit
    return (c == '0' || c == '1' || c == ' ' || c == '\r') && (c != '\n');
//Post condition: Returns true given the set inputs
}

//Pre condition: Takes in an ifstream object from an outside file opened in main.cpp
void BConvert::dConvert(ifstream& infile){ //Function that converts binary to decimal and prints result
    char c;
    int decimal = 0;
    bool leadingSpaces = true;
    string binaryNumber;
    bool isValid = true; // Flag indicates valid binary number
    
    while (infile.get(c)) {
        if (leadingSpaces){ // Skip leading spaces
            if (c == ' '){
                continue;
            }
            else{
                leadingSpaces = false;
            }
        }
        if (c == '0' || c == '1'){ // Process the valid binary inputs
            if (isValid){
                decimal = decimal * 2 + (c - '0');
                binaryNumber += c; // Adds the chars to a string to output to the screen
            }
        }
        else if (c == '\n'){ // Deals with the end of a line
            if (isValid){
                printResult(decimal, binaryNumber);
            }
            else {
                cout << "Digit in input is not valid" << endl;
            }
            decimal = 0;
            leadingSpaces = true;
            binaryNumber.clear();
            isValid = true; // Reset for the next binary
        }
        else if (c == ' '){ // Handling invalid spaces inside a binary number
            isValid = false;
        }
        else { //Handling characters that are not binary numbers
            cout << "Digit in input is not valid" << endl;
            while (infile.get(c) && c != '\n'){}
            decimal = 0;
            leadingSpaces = true;
            binaryNumber.clear();
            isValid = true; // Reset for the next binary
        }
    }
    if (isValid){ // Print the result even if there is not a end of line character to show the binary number is complete
        printResult(decimal, binaryNumber);
    }
    infile.close();
}
// Post condition: Reads in number from file, converts to decimal, and outputs the result. Also marks and prints error message for invalid inputs

