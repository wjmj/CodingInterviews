#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot, int value)
{
    if (pRoot == NULL || value <= 0)
        return;

    vector<BinaryTreeNode*> path;
    int residual;
    path.insert(pRoot->m_nValue);
    residual = value - pRoot->m_nValue;
    while (!path.empty())
    {
        if 
int main()
{
    return 0;
}
