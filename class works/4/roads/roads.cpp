#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct point {
    int value;
    char skobka;
};

bool comp(point x, point y);
int countBrigade(const std::vector<point>& points, int m);

int main()
{
    ifstream inputFile("input9.txt");
    ofstream outputFile("output.txt");
    int n, m, x, y, count;
    point x_point, y_point;
    count = 0;
    std::vector<point> points;
    inputFile >> n >> m;
    for (int i = 0; i < n; i++) {
        inputFile >> x;
        inputFile >> y;
        x_point.value = x;
        y_point.value = y;
        x_point.skobka = '[';
        y_point.skobka = ']';
        points.push_back(x_point);
        points.push_back(y_point);
    }
    sort(points.begin(), points.end(), comp);
    count = countBrigade(points, m);
    outputFile << count << std::endl;
}

int countBrigade(const std::vector<point>& points, int m) {
    int count = 0;
    int brigades = 0;
    bool flag = false;
    int lastPos = 0;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].skobka == '[') count++; else {
            count--;
            if ((count == m-1) && (lastPos == points[i].value)) brigades--;
        }
        if ((count == m) && (!flag)) {
            brigades++;
            flag = true;
            lastPos = points[i].value;
        }
        if (count == m-1) flag = false;
    }
    return brigades;
}

bool comp(point x, point y) {
    return (x.value < y.value) || ((x.value == y.value) && (x.skobka < y.skobka));
}


