#include <iostream>
#include <cstring>

using namespace std;

//len 为数组的长度，而不是字符串的长度
char* Replace(char str[], int len)
{
    if (str == NULL)
        return NULL;
    
    int strLen = strlen(str);

    int blankNum = 0;
    for (int i = 0; i < strLen; i++)    
    {
        if (str[i] == ' ')
            blankNum++;
    }
    if (blankNum == 0)
        return str;
    
    int nlen = strLen + 2 * blankNum;

    if (nlen > len)
        return NULL;

    int i = strLen-1;
    int j = nlen - 1;
    for (; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            continue;
        }
        str[j--] = str[i];
    }
    str[nlen] = '\0';
    
    return str;
}
int main()
{
    char str1[10] = {' ', 'H', 'e', 'l', 'l', 'o'};
    cout << Replace(str1, 10) << endl;

    char str2[20] = {' ', 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', ' '};
    cout << Replace(str2, 20) << endl;
    return 0;
}
