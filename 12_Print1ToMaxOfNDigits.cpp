#include <iostream>
#include <cstring>

using namespace std;

void AddOne(char* num)
{
    int len = strlen(num);
    int c = 0;
    int end = num[0] - '0' + 1;
    if (end > 10)
    {
        end -= 10;
        c = 1;
    }
    num[0] = '0' + end;

    int i = 1;
    while (i < len && c > 0) 
    {
        end = num[i] - '0' + 1;
        c = 0;
        if (end > 10)
        {
            end -= 10;
            c = 1;
        }
        num[i] = '0' + end;
        i++;
    }

    if (c > 0)
    {
        num[i] = 1;
        num[i+1] = '\0';
    }
}

void Print(int n)
{
    if (n > 0)
    {
        char* max = new char[n+1];
        for (int i = 0; i < n; i++)
            max[i] = '9';
        max[n] = '\0';
        char* index = new char[n+1];
        index[0] = '1';
        index[1] = '\0';
        
        while (strcmp(index, max) != 0)
        {
            for (int i = strlen(index)-1; i >= 0; i--)
                cout << index[i];
            cout << endl;
            AddOne(index);
        }
    }
}

int main()
{
    cout << Print(1) << endl << endl;
    cout << Print(2) << endl << endl;
    cout << Print(10) << endl << endl;
    cout << Print(20) << endl << endl;
    cout << Print(30) << endl << endl;
    return 0;
}
