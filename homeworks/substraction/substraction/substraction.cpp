/*
19.24. Длинная разность (4)
Заданы два целых положительных числа. Требуется найти их разность. Запрещается использование библиотек длинной арифметики.
Ввод. В первых двух строках файла INPUT.TXT содержатся  два  целых  числа  M  и  N  (1 ≤ N < M  ≤ 10200).
Вывод. В единственной строке выходного файла OUTPUT.TXT необходимо вывести разность M – N.
Примеры
Ввод 1                   Ввод 2
123456787654321          1000000000000000
35                       1
Вывод 1                  Вывод 2
123456787654286          999999999999999

Куликова Дарья. ПС-22. Делала в Visual Studio.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string SubstractNumber(string& firstNumber, string& secondNumber);

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    string firstNumber, secondNumber;
    inputFile >> firstNumber >> secondNumber;
    outputFile << SubstractNumber(firstNumber, secondNumber);
    return 0;
}

string SubstractNumber(string& firstNumber, string& secondNumber)
{
    string result = "";
    int borrowDigit = 0;
    int j = secondNumber.size() - 1;
    for (int i = firstNumber.size() - 1; i >= 0; i--)
    {
        int tmpDigit = (firstNumber[i] - '0') - (j >= 0 ? (secondNumber[j] - '0') : 0)  - borrowDigit;
        if (tmpDigit >= 0)
        {
            if (i != 0 || tmpDigit != 0)
                result += to_string(tmpDigit);
            borrowDigit = 0;
        }
        else
        {
            result += to_string(tmpDigit + 10);
            borrowDigit = 1;
        }
        j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

