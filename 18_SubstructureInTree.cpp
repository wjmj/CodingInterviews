#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

bool EqualTree(BinaryTreeNode* aRoot, BinaryTreeNode* bRoot)
{
    if (aRoot == NULL && bRoot == NULL)
        return true;
    if (aRoot == NULL || bRoot == NULL)
        return false;
    if (aRoot->m_nValue == bRoot->m_nValue)
        return EqualTree(aRoot->m_pLeft, bRoot->m_pLeft) && EqualTree(aRoot->m_pRight, bRoot->m_pRight);
    return false;
}

bool HasSubtree(BinaryTreeNode* aRoot, BinaryTreeNode* bRoot)
{
    if (aRoot == NULL && bRoot == NULL)
        return true;
    if (aRoot == NULL || bRoot == NULL)
        return false;
    if (aRoot->m_nValue == bRoot->m_nValue)
    {
        bool res = EqualTree(aRoot->m_pLeft, bRoot->m_pRight) && EqualTree(aRoot->m_pRight, bRoot->m_pRight);
        if (res)
            return true;
    }
    return HasSubtree(aRoot->m_pLeft, bRoot) || HasSubtree(aRoot->m_pRight, bRoot);    
}

int main()
{
    return 0;
}
