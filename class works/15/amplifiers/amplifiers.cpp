#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <fstream>

// 1 тип: 2k - 1
// 2 тип: 2k + 1

using namespace std;

struct NumberType
{
    int value;
    int type;
};

const unsigned long int MAX_NUMBER = 1000000;
void InitArray(NumberType(&arr)[MAX_NUMBER]);
int FindWay(int curNumber, std::queue<unsigned long int>& numbers, NumberType(&arr)[MAX_NUMBER], int finishNum);
void printWay(NumberType(&arr)[MAX_NUMBER], int n);

NumberType numbers[MAX_NUMBER];

int main()
{
    ifstream inputFile("INPUT4.TXT");
    int n;

    inputFile >> n;
    InitArray(numbers);

    std::queue<unsigned long int> numbersQ;
    numbersQ.push(1);

    int result = FindWay(1, numbersQ, numbers, n);
    numbers[1].type = 3;
    if (!result) {
        printWay(numbers, n);
    }
    else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

void InitArray(NumberType(&arr)[MAX_NUMBER]) {
    for (int i = 0; i < MAX_NUMBER; i++) {
        arr[i].value = 0;
        arr[i].type = 0;
    }
}

int FindWay(int curNumber, std::queue<unsigned long int>& numbers, NumberType(&arr)[MAX_NUMBER], int finishNum) {
    int numAmp1, numAmp2;
    while (!numbers.empty()) {
        numAmp1 = curNumber * 2 - 1;
        numAmp2 = curNumber * 2 + 1;
        if (numAmp1 == finishNum) {
            arr[numAmp1].value = curNumber;
            arr[numAmp1].type = 1;
            return 0;
        }
        if (numAmp2 == finishNum) {
            arr[numAmp2].value = curNumber;
            arr[numAmp2].type = 2;
            return 0;
        }
        if ((numAmp1 >= 1) && (arr[numAmp1].type == 0)) {
            numbers.push(numAmp1);
            arr[numAmp1].value = curNumber;
            arr[numAmp1].type = 1;
        }
        if ((numAmp2 >= 1) && (arr[numAmp2].type == 0)) {
            numbers.push(numAmp2);
            arr[numAmp2].value = curNumber;
            arr[numAmp2].type = 2;
        }
        numbers.pop();
        curNumber = numbers.front();
    }
    std::cout << "no" << std::endl;
    return 1;
}

void printWay(NumberType(&arr)[MAX_NUMBER], int n) {
    //std::cout << "printWay" << std::endl;

    std::vector<int> resultVector;
    int parent = n;

    while (arr[parent].type != 3) {
        resultVector.push_back(arr[parent].type);
        parent = arr[parent].value;
    }

    std::cout << resultVector.size() << std::endl;
    for (int i = resultVector.size() - 1; i >= 0; i--) {
        std::cout << resultVector[i] << " ";
    }
}