#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

void printArray(char ar[100][100], std::ofstream &outFile, int n, int m);

int main() {
    int n, m;
    char ch;
    std::string str;
    char field[100][100];
    using namespace std;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    std::cin >> n;
    std::cin >> m;
    int i = 0;
    while (getline(inputFile, str)) {
        for (int j = 0; j < str.length(); ++j) {
            field[i][j] = str[j];
        }
        i++;
    }
    printArray(field, outputFile, n, m);
    return 0;
}

void printArray(char ar[100][100], std::ofstream &outFile, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            outFile << ar[i][j];
        }
        outFile << std::endl;
    }
}
