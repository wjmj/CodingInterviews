#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void Permutation(char* str)
{
    if (str != NULL)
    {
        int len = strlen(str);
        if (len < 2)
        {
            cout << str << endl;
            return;
        }
        sort(str, str+len);        
        do
        {
            cout << str << endl;
        }while (next_permutation(str, str+len));
        cout << endl;
    }
}

int main()
{
    char str1[] = "abc";
    Permutation(str1);

    char str2[] = "abc";
    Permutation(str2);

    char str3[] = "abcnml";
    Permutation(str3);

    return 0;
}
