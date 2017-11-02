#include <iostream>

using namespace std;

struct BinarySearchTreeNode
{
    int m_nValue;
    BinarySearchTreeNode* m_pLeft;
    BinarySearchTreeNode* m_pRight;
};

BinarySearchTreeNode* Convert(BinarySearchTreeNode* root)
{
    if (root == NULL)
        return NULL;
    BinarySearchTreeNode* pLeft = Convert(root->m_pLeft);
    BinarySearchTreeNode* pRight = Convert(root->m_pRight);
    if (pLeft == NULL)
    {
        if (pRight == NULL)
            return root;
        root->m_pRight = pRight;
        root->m_pLeft = NULL;
        pRight->m_pLeft = root;
        return root;
    }
    else
    {
        pLeft->m_pLeft = NULL;
        BinarySearchTreeNode* p = pLeft;
        while (p->m_pRight != NULL)
            p = p->m_pRight;
        p->m_pRight = root;
        root->m_pLeft = p;
        if (pRight == NULL)
            return pLeft;
        root->m_pRight = pRight;
        pRight->m_pLeft = root;
        return pLeft;
    }
}

void PrintList2(BinarySearchTreeNode* list)
{
    if (list != NULL)
    {
        BinarySearchTreeNode* p = list;
        while (p ->m_pRight != NULL)
            p = p->m_pRight;
        while (p != NULL)
        {
            cout << p->m_nValue << endl;
            p = p->m_pLeft;
        }
        cout << endl;
    }
}

void PrintList(BinarySearchTreeNode* list)
{
    if (list != NULL)
    {
        BinarySearchTreeNode* p = list;
        while (p != NULL)
        {
            cout << p->m_nValue << endl;
            p = p->m_pRight;
        }
        cout << endl;
    }
}

int main()
{
    BinarySearchTreeNode* root1 = new BinarySearchTreeNode;
    root1->m_nValue = 10;
    root1->m_pLeft = new BinarySearchTreeNode;
    root1->m_pLeft->m_nValue = 6;
    root1->m_pLeft->m_pLeft = new BinarySearchTreeNode;
    root1->m_pLeft->m_pLeft->m_nValue = 4;
    root1->m_pLeft->m_pLeft->m_pLeft = NULL;
    root1->m_pLeft->m_pLeft->m_pRight = NULL;
    root1->m_pLeft->m_pRight = new BinarySearchTreeNode;
    root1->m_pLeft->m_pRight->m_nValue = 8;
    root1->m_pLeft->m_pRight->m_pLeft = NULL;
    root1->m_pLeft->m_pRight->m_pRight = NULL;
    root1->m_pRight = new BinarySearchTreeNode;
    root1->m_pRight->m_nValue = 14;
    root1->m_pRight->m_pLeft = new BinarySearchTreeNode;
    root1->m_pRight->m_pLeft->m_nValue = 12;
    root1->m_pRight->m_pLeft->m_pLeft = NULL;
    root1->m_pRight->m_pLeft->m_pRight = NULL;
    root1->m_pRight->m_pRight = new BinarySearchTreeNode;
    root1->m_pRight->m_pRight->m_nValue = 16;
    root1->m_pRight->m_pRight->m_pLeft = NULL;
    root1->m_pRight->m_pRight->m_pRight = NULL;
    
    BinarySearchTreeNode* list1 = Convert(root1);
    PrintList(list1);
    PrintList2(list1);
    return 0;
}
