#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
std::vector<int> a(100); // исходный массив
std::vector<int> tree(400);

void menuComands();
void initTree(int v, int L, int R);
int findMax(int v, int L, int R, int l, int r);
int Rmq(int a, int b);
void add1(int i, int x);
void printArray();


int main()
{
    int number;
    std::cout << "write n" << std::endl;
    std::cin >> n;
    std::cout << "write array" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> number;
        a.push_back(number);
    }
    initTree(0, 0, n);
    menuComands();
}

void menuComands()
{
    int comand = 5;
    while (comand != 0)
    {
        std::cout << "1 - Rmq" << std::endl;
        std::cout << "2 - Add1" << std::endl;
        std::cout << "3 - Add2" << std::endl;
        std::cout << "For exit write 0" << std::endl;
        std::cin >> comand;
        if (comand == 1)
        {
            int i, j, resultMax;
            std::cout << "Write i and j" << std::endl;
            std::cin >> i >> j;
            resultMax = Rmq(i-1, j);
            std::cout << "Result: " << resultMax << std::endl;
        }
        else if (comand == 2)
        {
            int index, x;
            std::cout << "Write index and x" << std::endl;
            std::cin >> index >> x;
            add1(index, x);
        }
        else if (comand == 3)
        {
            //add2
        }
        else
        {
            std::cout << "Ucorrect comand" << std::endl;
        }
    }
}

void initTree(int v, int L, int R)
{
    if (L == R - 1) 
    {
        if (L < n) 
        {
            tree[v] = a[L];
        }
        return; 
    }
    int M = (L + R) / 2; 
    initTree(2 * v + 1, L, M);
    initTree(2 * v + 2, M, R);
    tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]); 
}

int findMax(int v, int L, int R, int l, int r) 
{
    if (r <= L || R <= l) return 0;
    if (l <= L && R <= r) return tree[v];
    int M = (L + R) / 2;
    int first_child = findMax(2 * v + 1, L, M, l, r);
    int second_child = findMax(2 * v + 2, M, R, l, r);
    int maxValue = max(first_child, second_child);
    return maxValue;
}

int Rmq(int l, int r)
{
    int max = findMax(0, 0, n, l, r);
    return max;
}

void addValue(int v, int L, int R, int i, int x)
{
    if (L == R - 1)
    {
        tree[v] = a[i] + x;
        a[i] = a[i] + x;
        return;
    }
    int M = (L + R) / 2;
    if (i < M) addValue(2 * v + 1, L, M, i, x);
    else addValue(2 * v + 2, M, R, i, x);
    tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
}

void add1(int i, int x)
{
    addValue(0, 0, n, i-1, x);
    printArray();
}

void printArray()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}