// fermer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath> 
#include <vector>

int minS[100003];
int main()
{
    using namespace std;
    int n;
    std::ifstream inputFile("input.txt");
    inputFile >> n;
    std::cout << n << std::endl;
    vector<int> qSquare;
    for (int i = 4; i < 100003; i++) {
        minS[i] = -1;
    }
    minS[0] = 0; minS[1] = 1; minS[2] = 2; minS[3] = 3;
    for (int m = 4; m <= n; m++) { //подсчет вариантов
        for (int i = 1; i <= m; i++) {
            if (m - i * i >= 0) {
                int k = m - i * i;
                qSquare.push_back(k);
            }
        }
        int minimumSquare = INT_MAX;
        int temp = 0;
        for (int l = 0; l < qSquare.size(); l++) {
            for (int p = 0; p < qSquare.size(); p++) {
                temp = min(minS[qSquare[l]], minS[qSquare[p]]) + 1;
                if (temp < minimumSquare)
                {
                    minimumSquare = temp;
                }
            }
        }
        minS[m] = minimumSquare;
        qSquare.clear();
    }
    std::cout << minS[n];
}


