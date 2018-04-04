#include <iostream>
#include <cstdio>

using namespace std;

int NumberOf1(int n)
{
    if (n <= 0)
        return 0;
    int base = 1;
    int sum = 0;
    while (true)
    {
        int round = n / (base*10);
        int weight = (n/base) % 10;
        int low = n % base;
        
        sum += round * base;
        if (weight > 1)
            sum += base;
        else if (weight == 1)
            sum += low + 1;

        if (round == 0)
            break;
        base *= 10;
    }

    return sum;
}


int main()
{
    cout << NumberOf1(-1) << endl;
    cout << NumberOf1(0) << endl;
    cout << NumberOf1(1) << endl;
    cout << NumberOf1(12) <<endl;
} 
