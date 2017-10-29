#include <iostream>
#include <deque>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void Mirror(BinaryTreeNode* root)
{
    if (root == NULL)
        return;
    BinaryTreeNode* temp = root->m_pLeft;
    root->m_pLeft = root->m_pRight;
    root->m_pRight = temp;
    Mirror(root->m_pLeft);
    Mirror(root->m_pRight);
}

void PrintBinaryTree(BinaryTreeNode* root)
{
    deque<BinaryTreeNode*> q1, q2;
    q1.push_back(root);
    do
    {
        do
        {
            BinaryTreeNode* u = q1.front();
            q1.pop_front();
            cout << u->m_nValue << " ";
            if (u->m_pLeft)
                q2.push_back(u->m_pLeft);
            if (u->m_pRight)
                q2.push_back(u->m_pRight);
        }while (!q1.empty());
        cout << endl;
        q1.swap(q2);
    }while (!q1.empty());
}
       
int main()
{
    BinaryTreeNode* root1 = new BinaryTreeNode;
    root1->m_nValue = 1;
    root1->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_nValue = 2;
    root1->m_pRight = new BinaryTreeNode;
    root1->m_pRight->m_nValue = 3;
    root1->m_pLeft->m_pLeft = NULL;
    root1->m_pLeft->m_pRight = new BinaryTreeNode;
    root1->m_pLeft->m_pRight->m_nValue = 4;
    root1->m_pLeft->m_pRight->m_pLeft = NULL;
    root1->m_pLeft->m_pRight->m_pRight = NULL;
    root1->m_pRight->m_pLeft = new BinaryTreeNode;
    root1->m_pRight->m_pLeft->m_nValue = 5;
    root1->m_pRight->m_pLeft->m_pLeft = NULL;
    root1->m_pRight->m_pLeft->m_pRight = NULL;
    root1->m_pRight->m_pRight = NULL;

    PrintBinaryTree(root1);
    Mirror(root1);
    PrintBinaryTree(root1);

    return 0;
}
