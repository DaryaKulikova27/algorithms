#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void InitField(vector<vector<char>>& field, ifstream& inputFile, int n, int m);
void Metka(vector<vector<char>>& field, int i, int j, int& count, int& maxCount);
int CountPotato(vector<vector<char>>& field, int n, int m);

int main()
{
    ifstream inputFile("input5.txt");
    ofstream outputFile("output.txt");
    int n, m;
    inputFile >> n >> m;
    vector<vector<char>> field(n + 2, vector<char>(m + 2));
    InitField(field, inputFile, n, m);
    
    
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
    
    int result = CountPotato(field, n , m) + 1;
    std::cout << "result: " << result;

    return 0;
}

void InitField(vector<vector<char>>& field, ifstream& inputFile, int n, int m)
{
    char bed;
    for (int j = 0; j <= m + 1; j++) field[0][j] = '.';
    for (int j = 0; j <= m + 1; j++) field[n+1][j] = '.';
    for (int i = 1; i <= n; i++)
    {
        field[i][0] = '.';
        field[i][m + 1] = '.';
        for (int j = 1; j <= m; j++)
        {
            inputFile >> bed;
            field[i][j] = bed;
        }
    }
}

void Metka(vector<vector<char>>& field, int i, int j, int& count, int& maxCount)
{
    if (field[i][j] == '#')
    {
        if ((field[i + 1][j] != '#') && (field[i - 1][j] != '#') && (field[i][j+1] != '#') && (field[i][j-1] != '#'))
        {
            if (count > maxCount) maxCount = count;
            count--;
        }
        field[i][j] = '.';
        count++;
        Metka(field, i + 1, j, count, maxCount);
        Metka(field, i - 1, j, count, maxCount);
        Metka(field, i, j + 1, count, maxCount);
        Metka(field, i, j - 1, count, maxCount);
    }
    else 
    {
        if (count > maxCount) maxCount = count;
        //if (count != 0) count--;
    }
}

int CountPotato(vector<vector<char>>& field, int n, int m)
{
    int count;
    int maxCount = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            count = 0;
            Metka(field, i, j, count, maxCount);
            if (count > maxCount) maxCount = count;
        }
    }
    return maxCount;
}