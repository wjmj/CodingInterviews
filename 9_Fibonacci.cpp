#include <iostream>

using namespace std;

int Fibonacci(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    int a = 1;
    int b = 1;
    int res = 0;
    for (int i = 2; i <= n; i++)
    {
        res = a + b;
        a = b;
        b = res;
    }
    return res;
}

int main()
{
    for (int i = 0; i < 10;i++)
        cout << Fibonacci(i) << endl;
    return 0;
}
