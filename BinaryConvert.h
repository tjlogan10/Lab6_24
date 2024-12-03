#ifndef BINARYCONVERT_H
#define BINARYCONVERT_H
#include <string>
#include <fstream>
using namespace std;

class BConvert {
public:
    BConvert();
    ~BConvert();
    
    void dConvert(ifstream& infile);
private:
    void printResult(int decimal, string binaryNumber);
    bool validBinary(char c);
};
#endif // !BINARYCONVERT_H
