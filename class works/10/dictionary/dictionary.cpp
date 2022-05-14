#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
std::multiset<string> FindDictionaryWord(std::multiset<string>& dictionary, std::multiset<char>& mainWordLetters, int& score);void PrintSet(std::multiset<string>& thisSet);
void PrintSet(std::multiset<string>& thisSet);
bool comp(std::string x, std::string y);

int main()
{
    ifstream inputFile("input7.txt");
    ofstream outputFile("output.txt");
    std::string mainWord, dictionaryWord;
    std::multiset<string> dictionary;
    std::multiset<string> resultSet;
    int score = 0;
    std::multiset<char> mainWordLetters;
    inputFile >> mainWord;
    while ((getline(inputFile, dictionaryWord))) {
        dictionary.insert(dictionaryWord);
    }

    //загрузили все буквы главного слова во множество
    for (int i = 0; i < mainWord.length(); i++) {
        mainWordLetters.insert(mainWord[i]);
    }

    resultSet = FindDictionaryWord(dictionary, mainWordLetters, score);
    std::cout << score << std::endl;
    PrintSet(resultSet);

    return 0;
}

std::multiset<string> FindDictionaryWord(std::multiset<string>& dictionary, std::multiset<char>& mainWordLetters, int& score) {
    std::multiset<char> mainWordLettersCopy;
    std::multiset<string> resultWordSet;
    std::multiset<string>::iterator it = dictionary.begin();
    bool letterIsFound = true;
    for (; it != dictionary.end(); it++) {
        //проход по словам
        std::string dictionaryWord = *it;
        mainWordLettersCopy = mainWordLetters;

        //проход по буквам данного слова
        int i = 0;
        for (i = 0; i < dictionaryWord.length(); i++) {
            multiset<char>::iterator it = mainWordLettersCopy.find(dictionaryWord[i]);
            
            if (it == mainWordLettersCopy.end()) {
                break;
            }
            mainWordLettersCopy.erase(it);
        }
        //если слово из словаря можно составить из главного слова, то помещаем его в резльтирующее множество и считаем очки
        if (i == dictionaryWord.length()) {
            resultWordSet.insert(dictionaryWord);
            score += dictionaryWord.length();
        }
    }
    return resultWordSet;
}

bool comp(std::string x, std::string y)
{
    bool flag = false;
    if (x.length() > y.length()) {
        flag = true;
    }
    else if (x.length() == y.length()) {
        if (x < y) flag = true;
        /*int i = 0;
        while (x[i] == y[i]) i++;
        if (x[i] < y[i]) flag = true;*/
    }
    return flag;
}

void PrintSet(std::multiset<string>& thisSet) {
    std::vector<string> sortedVector;
    std::multiset<string>::iterator it = thisSet.begin();
    for (; it != thisSet.end(); it++) {
        sortedVector.push_back(*it);
    }
    sort(sortedVector.begin(), sortedVector.end(), comp);
    for (int i = 0; i < sortedVector.size(); i++) {
        std::cout << sortedVector[i] << std::endl;
    }
}
