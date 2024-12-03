/*
 Travis Logan
 C++ Fall 2024
 Due: Dec. 3 2024
 Lab 6: Binary to Decimal Conversion
 Lab Description: The goal of this lab is to write a program that reads characters representing binary numbers from a file and translate them to decimal. The binary and decimal numbers should be output in two columns with appropriate headings. The code should handle bad inputs and continue executing with the proper inputs.
 */
#include "BinaryConvert.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    BConvert Converter; //Creating an object called Converter
    
    cout << setw(30) << left << "Binary Number" << setw(24) << right << "Decimal Equivalent" << endl; // Header to help format the two types of numbers
    
    ifstream infile("/Users/tjlogan/Desktop/Lab6_24/BinaryIn.dat.txt");
    
    if (!infile.is_open()){ // Opens the file and sends a message if an error occurs
        cout << "Error opening file" << endl;
    }
    Converter.dConvert(infile);
    infile.close();
    return 0;
}
