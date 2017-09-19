//convert a string to an integer
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int error = 0;

int StrToInt(char* str)
{
    if (str == NULL || strcmp(str, "") == 0)
    {
        error = -1;
        return -1;
    }
    
    bool flag = true;
    unsigned int len = strlen(str);
    char* string = str;
    
    switch (string[0])
    {
    case '+':
    case '-':
        if (string[0] == '-')
            flag = false;
        if (len < 2 || (string[1] < '0' || string[1] > '9'))
        {
            error = -1;
            return -1;
        }
        string += 1;
        break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        break;
    default:
        error = -1;
        return -1;
    }
    
    long long res = 0;
    while (string[0] != '\0')
    {
        if (string[0] < '0' || string[0] > '9')
            break;
        res = res * 10 + string[0] - '0';
        if (res > INT_MAX)
        {
            error = -1;
            return -1;
        }
        string++;
    }

    res = flag ? res : -res;    
    return res;           
}

int main()
{
    cout << StrToInt(NULL) << endl;
    cout << StrToInt("") << endl;
    cout << StrToInt("+") << endl;
    cout << StrToInt("a123") << endl;
    cout << StrToInt("-123") << endl;
    cout << StrToInt("123") << endl;
}
