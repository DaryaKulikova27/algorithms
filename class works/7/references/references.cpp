#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

void TopologicalSort(int v, vector<bool>& visited, vector <vector<int>>& graph,
	const int& k, queue<int>& qResult);

int main()
{
	ifstream inputFile("input0.txt");
	int k, temp, numberOfReferences;
	inputFile >> k;
	vector < vector <int> > graph(k + 1, vector <int>(k + 1));
	queue<int> qResult;
	
	//заполнение графа
	for (int i = 1; i <= k; i++) {

		for (int j = 1; j <= k; j++) {
			graph[i][j] = false;
		}

		inputFile >> numberOfReferences;
		for (int m = 0; m < numberOfReferences; m++) {
			inputFile >> temp;
			graph[i][temp] = true;
		}
	}


	//проверка на корректность графа
	/*for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++) 
			cout << graph[i][j] << ' '; 
		cout << endl;
	}
	*/

	vector<bool> visited(k+1, false);
	
	// Вызываем рекурсивную вспомогательную функцию 
	// для поиска топологической сортировки для каждой вершины
	for (int i = 1; i <= k; i++) {
		if (visited[i] == false) {
			TopologicalSort(i, visited, graph, k, qResult);
		}
	}

	// Выводим содержимое стека
	while (!qResult.empty())
	{
		int val = qResult.front();
		qResult.pop();
		std::cout << val << std::endl;
	}

	return 0;
}

void TopologicalSort(int v, vector<bool>& visited, vector <vector<int>>& graph, 
	const int& k, queue<int>& qResult) {
	visited[v] = true;

	// Рекурсивно вызываем функцию для всех смежных вершин
	for (int i = 1; i <= k; i++) {
		if (graph[v][i]) {
			if (!visited[i]) TopologicalSort(i, visited, graph, k, qResult);
		}
	}
	qResult.push(v);
}


