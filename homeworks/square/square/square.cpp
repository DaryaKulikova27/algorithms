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

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void ReadPoints(int m, std::ifstream& inputFile, std::set<std::pair<int, int>>& pointSet);
int GetDoubleLength(pair<int, int>& point1, pair<int, int>& point2);
bool IsSquare(std::set<std::pair<int, int>>& pointSet);

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	int m, n;
	set<pair<int, int>> pointSet;
	inputFile >> m;
	ReadPoints(m, inputFile, pointSet);
	inputFile >> n;
	ReadPoints(n, inputFile, pointSet);


	/*for (auto& it : pointSet)
	{
		cout << it.first << " " << it.second << endl;
	}*/
	if (IsSquare(pointSet))
		outputFile << "Yes";
	else
		outputFile << "No";
	return 0;
}

void ReadPoints(int m, std::ifstream& inputFile,std::set<std::pair<int, int>>& pointSet)
{
	int x, y;
	for (int i = 0; i < m; i++)
	{
		inputFile >> x >> y;
		pair<int, int> point{ x, y };
		if (pointSet.find(point) == pointSet.end())
			pointSet.insert(point);
		else
			pointSet.erase(point);
	}
}

bool IsSquare(std::set<std::pair<int, int>>& pointSet)
{
	map<int, int> dublicateCounters;
	for (auto point1 : pointSet)
		for (auto point2 : pointSet)
			if (point1 != point2)
			{
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

int GetDoubleLength(pair<int, int>& point1, pair<int, int>& point2)
{
	return (point2.first - point1.first) * (point2.first - point1.first) + (point2.second - point1.second) * (point2.second - point1.second);
}




