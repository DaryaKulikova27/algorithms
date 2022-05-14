#include <iostream>
#include <vector>

using namespace std;

int n;
std::vector<int> a;
std::vector<int> t;

void init(vector<int> a);
void menuComands();
void init(int nn);
int sum(int r);
void inc(int i, int delta);
int sum(int l, int r);
void add(int k, int x);
void printArr(const std::vector<int>& t);

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

    //инициализация входного массива
    init(a);
    menuComands();
    
    return 0;
}

void menuComands()
{
    int comand = 5;
    while (comand != 0)
    {
        std::cout << "1 - Rsq" << std::endl;
        std::cout << "2 - Add" << std::endl;
        std::cout << "3 - Update" << std::endl;
        std::cout << "For exit write 0" << std::endl;
        std::cin >> comand;
        if (comand == 1)
        {
            int i, j, resultSum;
            std::cout << "Write i and j" << std::endl;
            std::cin >> i >> j;
            resultSum = sum(i, j);
            std::cout << "Result: " << resultSum << std::endl;
        }
        else if (comand == 2)
        {
            int k, delta;
            std::cout << "Write k and delta" << std::endl;
            std::cin >> k >> delta;
            add(k, delta);
        } 
        else if (comand == 3)
        {
            //update
        }
        else
        {
            std::cout << "Ucorrect comand" << std::endl;
        }
    }
}

void init(int nn)
{
    n = nn;
    t.assign(n, 0);
}

int sum(int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += t[r];
    return result;
}

void inc(int i, int delta)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] += delta;
}

int sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

void init(vector<int> a)
{
    init((int)a.size());
    for (unsigned i = 0; i < a.size(); i++)
        inc(i, a[i]);
}

// прибавление к элементу величины x
void add(int k, int x) {
    std::cout << "a[k] = " << a[k] << std::endl;
    a[k] += x;

    for (; k <= n; k += k & -k)
        t[k] += x;

    std::cout << "Numbers Vector: ";
    printArr(a);

    std::cout << "TreeState: ";
    printArr(t);
}

void printArr(const std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
