#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    std::vector<Point> points;
    int n, leftTurnsCounter;
    leftTurnsCounter = 0;
    ifstream inputFile("input5.txt");
    ofstream outputFile("output.txt");
    inputFile >> n;
    Point t;
    for (int i = 0; i < n; i++) {
        inputFile >> t.x >> t.y;
        points.push_back(t);
    }

    for (int i = 0; i < n; i++) {
        std::cout << points[i].x << " " << points[i].y << std::endl;
    }

    int i = 0;
    while(i <= n - 3) {
        if (((points[i + 1].x - points[i].x) * (points[i + 2].y - points[i].y) - (points[i + 2].x - points[i].x) * (points[i + 1].y - points[i].y)) >= 0) leftTurnsCounter++;
        i++;
    }
    std::cout << leftTurnsCounter;
    return 0;
}

