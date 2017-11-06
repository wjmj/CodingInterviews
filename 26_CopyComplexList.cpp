#include <iostream>

using namespace std;

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

void PrintComplexList(ComplexListNode* pHead)
{
    ComplexListNode* p = pHead;
    while (p != NULL)
    {
        cout << p->m_nValue << " ";
        p = p->m_pNext;
    }
    cout << endl;
    p = pHead;
    while (p != NULL)
    {
        if (p->m_pSibling != NULL)
            cout << p->m_nValue << " " << p->m_pSibling->m_nValue << endl;
        p = p->m_pNext;
    }
    cout << endl;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
    if (pHead == NULL)
        return NULL;
    int length = 0;
    ComplexListNode* p = pHead;
    while (p != NULL)
    {
        length++;
        p = p->m_pNext;
    }
    
    int* values = new int[length];
    int* sibling = new int[length];

    p = pHead;
    int k = 0;
    while (p != NULL)
    {
        values[k] = p->m_nValue;
        sibling[k] = -1;
        if (p->m_pSibling != NULL)
        {

            int i = 0;
            ComplexListNode* temp = pHead;
            while (temp != NULL)
            {
                if (temp == p->m_pSibling)
                {
                    sibling[k] = i;
                }
                i++;
                temp = temp->m_pNext;
            }
        }
        p = p->m_pNext;
        k++;
    }

    ComplexListNode** nodes = new ComplexListNode*[length];
    for (int i = 0; i <  length; i++)
    {
        nodes[i]  = new ComplexListNode;
        nodes[i]->m_nValue = values[i];
        nodes[i]->m_pNext = NULL;
        nodes[i]->m_pSibling = NULL;
    }

    for (int i = 0; i < length; i++)
    {
        if (i != length-1)
            nodes[i]->m_pNext = nodes[i+1];
        if (sibling[i] != -1)
            nodes[i]->m_pSibling = nodes[sibling[i]];
    }

    return nodes[0];
}

int main()
{
    ComplexListNode* pHead1 = new ComplexListNode;
    pHead1->m_nValue = 1;
    pHead1->m_pSibling = NULL;
    pHead1->m_pNext = new ComplexListNode;
    pHead1->m_pNext->m_pSibling = NULL;
    pHead1->m_pNext->m_nValue = 2;
    pHead1->m_pNext->m_pNext = new ComplexListNode;
    pHead1->m_pNext->m_pNext->m_nValue = 3;
    pHead1->m_pNext->m_pNext->m_pSibling = NULL;
    pHead1->m_pNext->m_pNext->m_pNext = new ComplexListNode;
    pHead1->m_pNext->m_pNext->m_pNext->m_nValue = 4;
    pHead1->m_pNext->m_pNext->m_pNext->m_pSibling = NULL;
    pHead1->m_pNext->m_pNext->m_pNext->m_pNext = new ComplexListNode;
    pHead1->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue = 5;
    pHead1->m_pNext->m_pNext->m_pNext->m_pNext->m_pSibling = NULL;
    pHead1->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext = NULL;
    
    pHead1->m_pSibling = pHead1->m_pNext->m_pNext;
    pHead1->m_pNext->m_pNext->m_pSibling = pHead1->m_pNext->m_pNext->m_pNext->m_pNext;
    pHead1->m_pNext->m_pNext->m_pNext->m_pSibling = pHead1->m_pNext;
    
    PrintComplexList(pHead1);
    ComplexListNode* cHead = Clone(pHead1);
    PrintComplexList(cHead);
    return 0;
}
