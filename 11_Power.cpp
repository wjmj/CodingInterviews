#include <iostream>

using namespace std;

double Power(double base, int exponent)
{
    if (base == 0)
        return 0;

    if (exponent == 0)
        return 1;

    if (exponent > 0)
    {
        
        if (exponent % 2 == 0)
            return Power(base, exponent/2) * Power(base, exponent/2);

        else
            return base * Power(base, exponent/2) * Power(base, exponent/2);
    }

    else
    {
        if (exponent % 2 == 0)
            return 1 / (Power(base, -exponent/2) * Power(base, -exponent/2));
        else
            return 1 / (base * Power(base, -exponent/2) * Power(base, -exponent/2));
    }
}

int main()
{
    cout << Power(0, 1) << endl;
    cout << Power(1, 2) << endl;
    cout << Power(9, 3) << endl;
  
    cout << Power(0, -1) << endl;
    cout << Power(1, -2) << endl;
    cout << Power(9, -3) << endl;

    cout << Power(-1, 2) << endl;
    cout << Power(-9, -3) << endl;

    cout << Power(1.2, 2) << endl;
    cout << Power(9.9, 2) << endl;

    cout << Power(1.2, -2) << endl;
    cout << Power(9.9, -3) << endl;

    cout << Power(-1.2, 2) << endl;
    cout << Power(-9.9, 3) << endl;

    return 0;
}
