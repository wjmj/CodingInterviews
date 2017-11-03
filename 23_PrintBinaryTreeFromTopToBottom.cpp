#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
    if (pRoot != NULL)
    {
        queue<BinaryTreeNode*> q;
        q.push(pRoot);
        
        while (!q.empty())
        {
            BinaryTreeNode* u = q.front();
            q.pop();
            cout << u->m_nValue << " ";
            if (u->m_pLeft)
                q.push(u->m_pLeft);
            if (u->m_pRight)
                q.push(u->m_pRight);
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode* root1 = new BinaryTreeNode;
    root1->m_nValue = 8;
    root1->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_nValue = 6;
    root1->m_pLeft->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_pLeft->m_nValue = 5;
    root1->m_pLeft->m_pLeft->m_pLeft = NULL;
    root1->m_pLeft->m_pLeft->m_pRight = NULL;
    root1->m_pLeft->m_pRight = new BinaryTreeNode;
    root1->m_pLeft->m_pRight->m_nValue = 7;
    root1->m_pLeft->m_pRight->m_pLeft = NULL;
    root1->m_pLeft->m_pRight->m_pRight = NULL;
    root1->m_pRight = new BinaryTreeNode;
    root1->m_pRight->m_nValue = 10;
    root1->m_pRight->m_pLeft = new BinaryTreeNode;
    root1->m_pRight->m_pLeft->m_nValue = 9;
    root1->m_pRight->m_pLeft->m_pLeft = NULL;
    root1->m_pRight->m_pLeft->m_pRight = NULL;
    root1->m_pRight->m_pRight = new BinaryTreeNode;
    root1->m_pRight->m_pRight->m_nValue = 11;
    root1->m_pRight->m_pRight->m_pLeft = NULL;
    root1->m_pRight->m_pRight->m_pRight = NULL;

    PrintFromTopToBottom(root1);
    return 0;
}
