//2.8. Калькулятор (7)
//Одна фирма выпускает в продажу странные калькуляторы. Они могут выполнять лишь три операции:
//ввести число 1;
//удвоить текущее число;
//поменять в текущем числе первую и последнюю цифры.
//Калькулятор умеет работать лишь с целыми числами от 1 до L (1 ≤ L ≤ 105). Незначащие нули в начале числа отбрасываются. Написать программу, которая проверяет, можно ли на данном калькуляторе получить число N (1 ≤ N ≤ 105). Если это возможно, выдать самую короткую последовательность преобразований.
//Ввод. В единственной строке находятся через пробел значения число L и N.
//Вывод. В первой строке вывести Yes или No. Если значение N достижимо, во второй строке выдать количество значений в цепочке преобразований от 1 до N, а в третьей строке через пробел сами эти значения.
//Куликова Дарья, ПС-22. Делала в CLion

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <fstream>

const int MAX_NUMBER = 100001;
int multTwo(int number);
int reverseDigit(int number);
void initArray(int (&arr)[MAX_NUMBER]);
int findWay(int number, std::queue<int> &numbers, int (&arr)[MAX_NUMBER], int borderNum, int finishNum);
void printWay(const int (&arr)[MAX_NUMBER], int finishNumber, std::ofstream& outputFile);

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile) {
        std::cerr << "i cant open input file" << std::endl;
        return 1;
    }
    if (!outputFile) {
        std::cerr << "i cant open output file" << std::endl;
        return 1;
    }
    int numbers[MAX_NUMBER];
    int L, N;
    inputFile >> L >> N;
    initArray(numbers);
    std::queue<int> numbersQ;
    numbersQ.push(1);
    numbers[1] = -1;
    int result = findWay(1, numbersQ, numbers, L, N);
    if (result == 0) {
        outputFile << "Yes" << std::endl;
        printWay(numbers, N, outputFile);
    } else {
        outputFile << "No" << std::endl;
    }
    return 0;
}

void printWay(const int (&arr)[MAX_NUMBER], int finishNumber, std::ofstream& outputFile) {
    std::vector<int> resultVector;
    int parent = finishNumber;
    while (parent != -1) {
        resultVector.push_back(parent);
        parent = arr[parent];
    }
    outputFile << resultVector.size() << std::endl;
    for (int i = resultVector.size()-1; i >= 0; i--) {
        outputFile << resultVector[i] << " ";
    }
}

void initArray(int (&arr)[MAX_NUMBER]) {
    for (int i = 0; i < MAX_NUMBER; i++) {
        arr[i] = 0;
    }
}

int findWay(int number, std::queue<int> &numbers, int (&arr)[MAX_NUMBER], int borderNum, int finishNum) {
    int multNum, reversedNum;
    while (!numbers.empty()) {
        multNum = multTwo(number);
        reversedNum = reverseDigit(number);
        if (multNum == finishNum) {
            arr[multNum] = number;
            return 0;
        }
        if (reversedNum == finishNum) {
            arr[reversedNum] = number;
            return 0;
        }
        if ((multNum >= 1) && (multNum <= borderNum) && (arr[multNum] == 0)) {
            numbers.push(multNum);
            arr[multNum] = number;
        }
        if ((reversedNum >= 1) && (reversedNum <= borderNum) && (arr[reversedNum] == 0)) {
            numbers.push(reversedNum);
            arr[reversedNum] = number;
        }
        numbers.pop();
        number = numbers.front();
    }
    return 1;
}

int multTwo(int number) {
    int result = number * 2;
    return result;
}

int reverseDigit(int number) {
    int newNum;
    std::vector<int> digits;
    int lastDigit, firstDigit, digit;
    while (number != 0) {
        digit = number % 10;
        digits.push_back(digit);
        number = number / 10;
    }
    firstDigit = digits.front();
    lastDigit = digits.back();
    digits[0] = lastDigit;
    digits[digits.size()-1] = firstDigit;
    newNum = 0;
    for (int i = 0; i < digits.size(); ++i) {
        newNum = newNum + digits[i] * pow(10, i);
    }
    return newNum;
}
