#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

void FindPrice(vector<size_t>& sellersMinprice, vector<size_t>& buyersMaxprice, ofstream& outputFile);
int getNumberOfBuyers(vector<size_t>& buyersMaxprice, size_t& price);
int getNumberOfSellers(vector<size_t>& sellersMinprice, size_t& price);

int main()
{
    ifstream inputFile("input7.txt");
    ofstream outputFile("output.txt");
    int n, m;
    inputFile >> n >> m;
    std::vector<size_t> sellersMinprice;
    std::vector<size_t> buyersMaxprice;
    size_t price;
    for (int i = 0; i < n; i++)
    {
        inputFile >> price;
        sellersMinprice.push_back(price);
    }
    for (int j = 0; j < m; j++)
    {
        inputFile >> price;
        buyersMaxprice.push_back(price);
    }

    /*
    for (int i = 0; i < n; i++)
    {
        cout << sellersMinprice[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m; i++)
    {
        cout << buyersMaxprice[i] << " ";
    }
    std::cout << std::endl;
    */

    FindPrice(sellersMinprice, buyersMaxprice, outputFile);

    return 0;
}

bool comp(int i, int j) { return i < j; }

void FindPrice(vector<size_t>& sellersMinprice, vector<size_t>& buyersMaxprice, ofstream& outputFile)
{
    size_t maxRevenue = 0;
    size_t optionalPrice = 0;
    size_t revenue;
    int numberOfBuyers, numberOfSellers, numberOfPurchases;
    for (size_t i = 0; i < buyersMaxprice.size(); i++)
    {
        numberOfBuyers = getNumberOfBuyers(buyersMaxprice, buyersMaxprice[i]); //количество готовых покупателей
        numberOfSellers = getNumberOfSellers(sellersMinprice, buyersMaxprice[i]); // количество готовых продавцов
        numberOfPurchases = min(numberOfBuyers, numberOfSellers);
        revenue = numberOfPurchases * buyersMaxprice[i];

        if (revenue > maxRevenue)
        {
            maxRevenue = revenue;
            optionalPrice = buyersMaxprice[i];
        }
        if ((revenue == maxRevenue) && (buyersMaxprice[i] < optionalPrice)) optionalPrice = buyersMaxprice[i];
    }
    std::cout << optionalPrice << " " << maxRevenue;
}

int getNumberOfSellers(vector<size_t>& sellersMinprice, size_t& price)
{
    int count = 0;
    for (size_t i = 0; i < sellersMinprice.size(); i++)
    {
        if (price >= sellersMinprice[i])
        {
            count++;
        }
    }
    return count;
}

int getNumberOfBuyers(vector<size_t>& buyersMaxprice, size_t& price)
{
    int count = 0;
    for (size_t i = 0; i < buyersMaxprice.size(); i++)
    {
        if (price <= buyersMaxprice[i]) count++;
    }
    return count;
}
