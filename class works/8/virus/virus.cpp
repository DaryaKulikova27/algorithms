#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

//void MetkaVirus(const Point& virus, vector <vector<int>>& field, queue<Point>& viruses, const int& n);
int CountMinStep(vector <vector<int>>& field, int& n);

int main()
{
    int n, m, minSteps;
    Point virus;
    ifstream inputFile("input10.txt");
    ofstream outputFile("output.txt");
    inputFile >> n >> m;
    vector < vector <int> > field(n + 1, vector <int>(n + 1));
    vector<Point> viruses;

    int x, y;
    for (int i = 0; i < m; i++) {
        inputFile >> x >> y;
        virus.x = x;
        virus.y = y;
        viruses.push_back(virus);
        field[x][y] = 1;
    }    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            field[i][j] = 0;
        }
    }

    int element, step, minStep;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            minStep = 10000;
            for (int k = 0; k < viruses.size(); k++) {
                step = abs(i - viruses[k].x) + abs(j - viruses[k].y);
                if (step < minStep) minStep = step;
            }
            field[i][j] = minStep;
        }
    }

    minSteps = CountMinStep(field, n);
    std::cout << minSteps;

    return 0;
}

/*void MetkaVirus(const Point& virus, vector <vector<int>>& field, queue<Point>& viruses, const int& n) {
    Point newVirus;

    if (virus.x != n) {
        newVirus.x = virus.x + 1;
        newVirus.y = virus.y;
        if (field[newVirus.x][newVirus.y] == 0) {
            viruses.push(newVirus);
        }
        field[newVirus.x][newVirus.y]++;
    }
   
    if (virus.x != 1) {
        newVirus.x = virus.x - 1;
        newVirus.y = virus.y;
        if (field[newVirus.x][newVirus.y] == 0) {
            viruses.push(newVirus);
        }
        field[newVirus.x][newVirus.y]++;
    }
    
    if (virus.y != n) {
        newVirus.x = virus.x;
        newVirus.y = virus.y + 1;
        if (field[newVirus.x][newVirus.y] == 0) {
            viruses.push(newVirus);
        }
        field[newVirus.x][newVirus.y]++;
    }
    
    if (virus.y != 1) {
        newVirus.x = virus.x;
        newVirus.y = virus.y - 1;
        if (field[newVirus.x][newVirus.y] == 0) {
            viruses.push(newVirus);
        }
        field[newVirus.x][newVirus.y]++;
    }
}*/


int CountMinStep(vector <vector<int>>& field, int& n) {
    int maxValue = field[1][1];

    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (field[i][j] > maxValue)
                maxValue = field[i][j];

    return maxValue;
}

