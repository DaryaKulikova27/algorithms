#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool IsArithmeticProgression(std::vector<int>& numbers);

int main()
{
	std::ifstream inputFile("in4.txt");
	int l, n, number;
	inputFile >> l;
	vector< vector<int>> numbers(l);
	for (int i = 0; i < l; i++)
	{
		inputFile >> n;
		for (int j = 0; j < n; j++)
		{
			inputFile >> number;
			numbers[i].push_back(number);
		}
	}

	for (int i = 0; i < l; i++)
	{
		std::cout << IsArithmeticProgression(numbers[i]) << std::endl;
	}
}

bool comp(int a, int b)
{
	return a < b;
}

bool IsArithmeticProgression(std::vector<int>& numbers)
{
	sort(numbers.begin(), numbers.end(), comp);
	int delta = numbers[1] - numbers[0];
	for (int i = 2; i < numbers.size(); i++)
	{
		if ((numbers[i] - numbers[i - 1]) != delta) return false;
	}
	return true;
}
