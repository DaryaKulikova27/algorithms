/*
11.3. Даешь квадрат (6)
Ломаная без самопересечений и самокасаний разделяет четырехугольник на две части, которые не лежат одна внутри другой. Каждая часть представляет собой многоугольник и задается отдельно путем перечисления координат вершин. Определить, является ли исходный четырехугольник квадратом.
Ввод из файла INPUT.TXT. В первой строке находится число M, задающее количество вершин первого многоугольника. Следующие M строк содержат пары целых чисел - координаты точек (Xi, Yi). Если соединить точки в данном порядке, а также первую и последнюю точки, то получится первый многоугольник. Далее аналогично указываются число N – количество вершин второго многоугольника и N строк с координатами его вершин. Таким образом, тест занимает M + N + 2 строк. Начальная вершина и направление обхода вершин каждого многоугольника могут быть произвольными.
Вывод в файл OUTPUT.TXT. Выводится единственная строка со значением Yes или No – является четырехугольник квадратом или нет.
Ограничения: 3 ≤ M, N ≤ 1000;  -100 ≤ Xi, Yi ≤ 100.
Примеры
Ввод 1     Ввод 2
6          8
0 0        0 0
0 1        0 6
1 1        5 5
1 2        5 0
2 2        3 0
2 0        4 1
4          1 1
0 2        2 0
1 2        4
1 1        1 1
0 1        2 0
           3 0
           4 1
Вывод 1    Вывод 2
Yes        No

Куликова Дарья. ПС-22. Делала в Visual Studio 2019.
*/

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

//void ReadPoints(int m, std::ifstream& inputFile, std::set<std::pair<int, int>>& pointSet);
int GetDoubleLength(pair<int, int>& point1, pair<int, int>& point2);
bool IsSquare(std::set<std::pair<int, int>>& pointSet);

pair<int, int> MakeEdge(int vertexID1, int vertexID2);
int GetVertexID(map<pair<int, int>, int>& vertices, const pair<int, int>& vertex);
void InsertRemoveEdge(set<pair<int, int>>& edges, const pair<int, int>& edge);
void ReadEdges(ifstream& inputFile, map<pair<int, int>, int>& vertices, set<pair<int, int>>& edges, int count);

void TryMergeEdges(map<int, pair<int, int>>& verticesIDs, set<pair<int, int>>& edges, int end1, int mid, int end2);
set<pair<int, int>> SimplifyPolygonEdges(map<int, pair<int, int>>& verticesIDs, set<pair<int, int>>& sourceEdges);
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int m, n;
    set<pair<int, int>> pointSet;
    map<pair<int, int>, int> vertices;
    map<int, pair<int, int>> verticesIDs;
    set<pair<int, int>> edges;

    inputFile >> m;
    ReadEdges(inputFile, vertices, edges, m);
    inputFile >> n;
    ReadEdges(inputFile, vertices, edges, n);

    for (auto pair : vertices)
        verticesIDs[pair.second] = pair.first;

    set<pair<int, int>> edges2 = SimplifyPolygonEdges(verticesIDs, edges);

    for (auto edgePair : edges2) {
        pointSet.insert(verticesIDs[edgePair.first]);
        pointSet.insert(verticesIDs[edgePair.second]);
    }


    if (IsSquare(pointSet))
        outputFile << "Yes";
    else
        outputFile << "No";
    return 0;
}

set<pair<int, int>> SimplifyPolygonEdges(map<int, pair<int, int>>& verticesIDs, set<pair<int, int>>& sourceEdges) {
    set<pair<int, int>> destinationEdges = set(sourceEdges);
    for (auto& edge1 : sourceEdges)
        for (auto& edge2 : sourceEdges)
            if (edge1 != edge2) {
                if (edge1.first == edge2.second)
                    TryMergeEdges(verticesIDs, destinationEdges, edge1.second, edge1.first, edge2.first);
                else if (edge1.first == edge2.first)
                    TryMergeEdges(verticesIDs, destinationEdges, edge1.second, edge1.first, edge2.second);
                else if (edge1.second == edge2.first)
                    TryMergeEdges(verticesIDs, destinationEdges, edge1.first, edge1.second, edge2.second);
                else if (edge1.second == edge2.second)
                    TryMergeEdges(verticesIDs, destinationEdges, edge1.first, edge1.second, edge2.first);
            }
    return destinationEdges;
}

void TryMergeEdges(map<int, pair<int, int>>& verticesIDs, set<pair<int, int>>& edges, int end1, int mid, int end2) {
    auto vEnd1 = verticesIDs[end1];
    auto vMid = verticesIDs[mid];
    auto vEnd2 = verticesIDs[end2];

    bool isBetween = abs(sqrt(GetDoubleLength(vEnd1, vMid)) + sqrt(GetDoubleLength(vEnd2, vMid)) - sqrt(GetDoubleLength(vEnd1, vEnd2))) < 0.001f;

    if (isBetween) {
        edges.erase(MakeEdge(end1, mid));
        edges.erase(MakeEdge(mid, end2));
        edges.insert(MakeEdge(end1, end2));
    }
}

void ReadEdges(ifstream& inputFile, map<pair<int, int>, int>& vertices, set<pair<int, int>>& edges, int count) {
    int x, y, previousVertexID = -1, firstVertexID;
    for (int i = 0; i < count; i++) {
        inputFile >> x >> y;
        pair<int, int> vertex{ x, y };

        int vertID = GetVertexID(vertices, vertex);

        if (previousVertexID >= 0)
            InsertRemoveEdge(edges, MakeEdge(previousVertexID, vertID));
        else
            firstVertexID = vertID;
        previousVertexID = vertID;
    }
    InsertRemoveEdge(edges, MakeEdge(previousVertexID, firstVertexID));
}

void InsertRemoveEdge(set<pair<int, int>>& edges, const pair<int, int>& edge) {
    if (edges.find(edge) == edges.end())
        edges.insert(edge);
    else
        edges.erase(edge);
}

int GetVertexID(map<pair<int, int>, int>& vertices, const pair<int, int>& vertex) {
    if (!vertices.contains(vertex))
        vertices[vertex] = (int)vertices.size();
    int vertID = vertices[vertex];
    return vertID;
}

pair<int, int> MakeEdge(int vertexID1, int vertexID2) {
    return vertexID1 > vertexID2 ? make_pair(vertexID2, vertexID1) : make_pair(vertexID1, vertexID2);
}

bool IsSquare(std::set<std::pair<int, int>>& pointSet) {
    map<int, int> dublicateCounters;
    for (auto point1 : pointSet)
        for (auto point2 : pointSet)
            if (point1 != point2) {
                int length = GetDoubleLength(point1, point2);

                if (dublicateCounters.find(length) != dublicateCounters.end())
                    dublicateCounters[length] = dublicateCounters[length] + 1;
                else
                    dublicateCounters.insert(make_pair(length, 1));
            }
    for (auto& lengthCount : dublicateCounters)
        if (lengthCount.second != 8 && lengthCount.second != 4)
            return false;
    return dublicateCounters.size() == 2;
}

int GetDoubleLength(pair<int, int>& point1, pair<int, int>& point2) {
    return (point2.first - point1.first) * (point2.first - point1.first) + (point2.second - point1.second) * (point2.second - point1.second);
}
