#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main() {
    using namespace std;
    ifstream inputFile("Input6.txt");
    ofstream outputFile("Output.txt");
    if (!inputFile)
    {
        cerr << "i cant open this file" << endl;
        exit(1);
    }
    std::string numberDigit;
    std::string number;
    getline(inputFile, numberDigit);
    getline(inputFile, number);
    int min = std::stoi(number.substr(0,1));
    unsigned int pos;
    for (unsigned int i = 0; i < number.length(); i++) {
        int digit = std::stoi(number.substr(i, 1));
        if (digit < min) {
            min = digit;
            pos = i;
        }
        if (digit > min) break;
    }
    outputFile << pos + 1 << std::endl;
    inputFile.close();
    outputFile.close();
    return 0;
};
