#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator= (const CMyString& str);
    void  print();
private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if (pData == NULL)
    {   
         m_pData = NULL;
    }
    else
    {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    if (str.m_pData == NULL)
    {
        m_pData = NULL;
    }
    else
    {
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }
}
/*
CMyString& CMyString::operator= (const CMyString& str)
{
    if (this != &str)
    {
        if (str.m_pData == NULL)
            m_pData = NULL;
        else
        {
            if (m_pData != NULL)
                delete [] m_pData;
            m_pData = new char[strlen(str.m_pData) + 1];
            strcpy(m_pData, str.m_pData);
        }
    }
    return *this;
} 
*/
CMyString& CMyString::operator= (const CMyString& str)
{
    if (this != &str)
    {
        CMyString temp(str);
        char* pTemp = temp.m_pData;
        temp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
void CMyString::print()
{
    if (m_pData != NULL)
    {
        cout << m_pData << endl;
    }
}   

CMyString::~CMyString()
{
    if (m_pData != NULL)
        delete [] m_pData;
}

int main()
{
    CMyString str1("hello");
    str1.print();
    CMyString str2(str1);
    str2.print();
    CMyString str3;

    str3 = str1;
    str3.print();

    CMyString str4("world");
    str3 = str4;
    str3.print();
    str1.print();
    
    return 0;
}
