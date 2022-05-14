#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
int main()
{
    ifstream inputFile("input1.txt");
    int n;
    inputFile >> n;
    vector<int> inversions(n);
    for (int& x : inversions) {
        inputFile >> x;
    }

    vector<int> resultVector(n);
    vector<int> check(n);

    for (int i = 0; i <= n-1; i++) {
        check[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        int j = 0; 
        int k = n - 1;
        while (j < inversions[i] || check[k]) {
            if (!check[k]) j++;
            k--;
        }
        resultVector[i] = k + 1;
        check[k] = 1;
    }

    ofstream outputFile("output.txt");
    for (int i = 0; i < n; i++) {
       cout << resultVector[i] << " ";
    }
    return 0;
}




