#include <iostream>

using namespace std;

void Permutation(char* str, char* begin)
{
    if (*begin == '\0')
    {
        cout << str << endl;
        return;
    }

    for (char* pch = begin; (*pch) != '\0'; ++pch)
    {
        char tmp = *begin;
        *begin = *pch;
        *pch = tmp;

        Permutation(str, begin+1);
        
        tmp = *begin;
        *begin = *pch;
        *pch = tmp;
    }
}

void Permutation(char* str)
{
    if (str == NULL)
        return;

    Permutation(str, str);
}
  
int main()
{
    char str1[] = "cba";
    Permutation(str1);

    char str2[] = "";
    Permutation(str2);

    char str3[] = "a";
    Permutation(str3);

    //char str4[] = "cfbajikl";
    //Permutation(str4);
    
    return 0;
}
