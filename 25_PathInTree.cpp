#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void FindPathCore(BinaryTreeNode* pRoot, int value, vector<int> &path)
{
    if (pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL)
    {
        if (value == pRoot->m_nValue)
        {
            path.push_back(pRoot->m_nValue);
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    int residual = value - pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    if (pRoot->m_pLeft != NULL)FindPathCore(pRoot->m_pLeft, residual, path);
    if (pRoot->m_pRight != NULL)FindPathCore(pRoot->m_pRight, residual, path);
    path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int value)
{
    if (pRoot == NULL)
        return;

    vector<int> path;
    FindPathCore(pRoot, value, path);
}
int main()
{
    BinaryTreeNode* root1 = new BinaryTreeNode;
    root1->m_nValue = 8;
    root1->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_nValue = 6;
    root1->m_pRight = new BinaryTreeNode;
    root1->m_pRight->m_nValue = 10;
    root1->m_pLeft->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_pLeft->m_nValue = 5;
    root1->m_pLeft->m_pLeft->m_pLeft = NULL;
    root1->m_pLeft->m_pLeft->m_pRight = NULL;
    root1->m_pLeft->m_pRight = new BinaryTreeNode;
    root1->m_pLeft->m_pRight->m_nValue = 7;
    root1->m_pLeft->m_pRight->m_pLeft = NULL;
    root1->m_pLeft->m_pRight->m_pRight = NULL;
    root1->m_pRight->m_pLeft = new BinaryTreeNode;
    root1->m_pRight->m_pLeft->m_nValue = 9;
    root1->m_pRight->m_pLeft->m_pLeft = NULL;
    root1->m_pRight->m_pLeft->m_pRight = NULL;
    root1->m_pRight->m_pRight = new BinaryTreeNode;
    root1->m_pRight->m_pRight->m_nValue = 11;
    root1->m_pRight->m_pRight->m_pLeft = NULL;
    root1->m_pRight->m_pRight->m_pRight = NULL;

    FindPath(root1, 19);
    FindPath(root1, 21);
    FindPath(root1, 29);
    FindPath(root1, 30);

    return 0;
}
