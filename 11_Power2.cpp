#include <iostream>

using namespace std;

const double MIN = 0.0000001;

bool g_invalidInput = false;

bool equal(double a, double b)
{
    if ((a - b < MIN) && (a -b > -MIN))
        return true;
    return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (equal(base, 0))
        return 0;
    if (exponent == 0)
        return 1.0;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result = result * result;

    if (exponent & 0x01)
        result *= base;

    return result;
}
    
double Power(double base, int exponent)
{
    g_invalidInput = false;
    if (equal(base, 0) && (exponent < 0))
    {
        g_invalidInput = true;
        return 0;
    }

    int e = exponent;
    if (exponent < 0)
        e = -exponent;

    double result = PowerWithUnsignedExponent(base, e);

    if (exponent < 0)
        result = 1.0 / result;

    return result;
}

int main()
{
    cout << Power(0, 0) << endl;
    cout << g_invalidInput << endl;

    cout << Power(0, 1) << endl;
    cout << g_invalidInput << endl;

    cout << Power(0, -1) << endl;
    cout << g_invalidInput << endl;

    cout << Power(2, 10) << endl;
    cout << g_invalidInput << endl;

    cout << Power(2, -10) << endl;
    cout << g_invalidInput << endl;

    cout << Power(2, 0) << endl;
    cout << g_invalidInput << endl;

    cout << Power(-2, 9) << endl;
    cout << g_invalidInput << endl;

    cout << Power(-2, 0) << endl;
    cout << g_invalidInput << endl;

    cout << Power(-2, -10) << endl;
    cout << g_invalidInput << endl;

    cout << Power(16, 1) << endl;

    return 0;
}
