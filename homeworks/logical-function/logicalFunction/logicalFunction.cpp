#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> pValues;
void FindWaysToGetUnit(std::string currentSequence, int step, int currentSelection, int n, int& maxOnes, std::string& resultSequence);

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	int n;
	char value;
	inputFile >> n;
	for (int i = 0; i < 4; i++)
	{
		inputFile >> value;
		pValues.push_back(value - '0');
	}
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << pValues[i] << " ";
	}
	string resultSequence = "";
	int maxOnes = 0;
	FindWaysToGetUnit("", 0, 1, n, maxOnes, resultSequence);
	outputFile << resultSequence;
	return 0;
}

void FindWaysToGetUnit(std::string currentSequence, int step, int currentSelection, int n, int& maxOnes, std::string& resultSequence)
{
	int countOnes = 0;
	if (step == n)
	{
		currentSequence += currentSelection;
		for (int i = 0; i < currentSequence.size(); i++)
			if (currentSequence[i] == '1') countOnes++;
		if (countOnes > maxOnes) 
		{
			maxOnes = countOnes;
			resultSequence = currentSequence;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
		if (pValues[i] == currentSelection) 
			FindWaysToGetUnit(((i & 1) ? "1" : "0") + currentSequence, step + 1, (i & 0b10) ? 1 : 0, n, maxOnes, resultSequence);
}

