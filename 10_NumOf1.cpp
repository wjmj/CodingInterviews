#include <iostream>

using namespace std;

int NumOf1(int num)
{
    int ans = 0;
    int x = num;
    int i= 0;
    while (i < sizeof(num) * 8)
    {
        if (x & 1)
            ans++;
        x = x >> 1;
        i++;
    }

    return ans;
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << NumOf1(i) << endl;
    for (int i = 1; i < 10; i++)
        cout << NumOf1(-i) << endl;
    return 0;
}
