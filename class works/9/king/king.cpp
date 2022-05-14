#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;
};

//void InitVisited(vector <vector<bool>>& visited, const int& n);
//int FindFinish(vector <vector<bool>>& visited, queue<Point>& coordinates, vector <vector<int>>& field);
int FindWinner(const Point& coordinate);


int main()
{
	ifstream inputFile("input5.txt");
	ofstream outputFile("output.txt");
	int m, n;
	n = 100000;
	Point coordinate;
	queue<Point> variants;
	//vector < vector <int> > field(n + 1, vector <int>(n + 1));
	//vector < vector <int> > visited(n + 1, vector <int>(n + 1));
	inputFile >> m;
	for (int i = 0; i < m; i++) {
		inputFile >> coordinate.y >> coordinate.x;
		variants.push(coordinate);
	}

	//queue<Point> coordinates;
	int result; 

	while (!variants.empty()) {
		coordinate = variants.front();
		variants.pop();
		result = FindWinner(coordinate);
		std::cout << result << std::endl;
	}

	return 0;
}

int FindWinner(const Point& coordinate) {
	int winner = 0;
	if ((coordinate.x % 2 != 0) && (coordinate.y % 2 != 0)) winner = 2;
	else winner = 1;
	return winner;
}

/*void InitVisited(vector <vector<int>>& visited, const int& n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = false;
		}
	}
}*/

/*int FindFinish(vector <vector<int>>& visited, queue<Point>& coordinates, vector <vector<int>>& field) {
	int count = 1;
	Point coordinate, newCoordinate;
	while (!coordinates.empty()) {
		coordinate = coordinates.front();
		coordinates.pop();
		visited[coordinate.x][coordinate.y] = 1;
		
		newCoordinate.x = coordinate.x - 1;
		newCoordinate.y = coordinate.y;
		if ((newCoordinate.x == 1) && (newCoordinate.y == 1)) break;
		if (!visited[newCoordinate.x][newCoordinate.y]) {
			coordinates.push(newCoordinate);
		}

		newCoordinate.x = coordinate.x - 1;
		newCoordinate.y = coordinate.y - 1;
		if ((newCoordinate.x == 1) && (newCoordinate.y == 1)) break;
		if (!visited[newCoordinate.x][newCoordinate.y]) {
			coordinates.push(newCoordinate);
		}


		newCoordinate.x = coordinate.x;
		newCoordinate.y = coordinate.y - 1;
		if ((newCoordinate.x == 1) && (newCoordinate.y == 1)) break;
		if (!visited[newCoordinate.x][newCoordinate.y]) {
			coordinates.push(newCoordinate);
		}
		count++;
		std::cout << count << " ";
	}
	count = count % 2;
	return count;
}
*/
