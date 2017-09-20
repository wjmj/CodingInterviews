/*************************************************************************
	> File Name: 04_ReplaceBlank.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Sep 2017 12:33:28 AM PDT
 ************************************************************************/

#include<iostream>
#include <cstring>

using namespace std;

char* Replace(char* str)
{
    if (str == NULL)
        return NULL;

    int len = strlen(str);
    char* string = new char[3*len];
    char* p = str;
    int i = 0;
    while (p[0] != '\0')
    {
        if (p[0] == ' ')
        {
            string[i++]  = '%';
            string[i++] =   '2';
            string[i++] = '0';
        }
        else
            string[i++] = p[0];
        p++;
    }
    string[i++] = '\0';
    
    return string;
}
int main()
{
    char* str1 = "Hello World";
    cout << Replace(str1) << endl;

    char* str2 = " Hello World";
    cout << Replace(str2) << endl;

    char* str3 = "Hello World ";
    cout << Replace(str3) << endl;
}
