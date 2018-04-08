#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int treeDepth(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return 0;
    int leftDepth = treeDepth(pRoot->m_pLeft);
    int rightDepth = treeDepth(pRoot->m_pRight);
    int depth = (leftDepth > rightDepth) ? leftDepth : rightDepth;

    return depth+1;
}
    
bool isBalanceTree(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return true;
    int diff = treeDepth(pRoot->m_pLeft) - treeDepth(pRoot->m_pRight);
    if (diff < 0) diff = -diff;
    if (diff > 1)
        return false;
    return isBalanceTree(pRoot->m_pLeft) && isBalanceTree(pRoot->m_pRight);
}

static void test(const char* testName, BinaryTreeNode* pRoot, bool expected)
{
    cout << testName << " Begins: ";
    bool result = isBalanceTree(pRoot);
    if (result == expected)
        cout << "Passed." << endl;
    else
        cout << "Failed" <<endl;
}

static void test1()
{
    BinaryTreeNode* pRoot;
    pRoot = new BinaryTreeNode;
    pRoot->m_nValue = 1;
    pRoot->m_pLeft = new BinaryTreeNode;
    pRoot->m_pLeft->m_nValue = 2;
    pRoot->m_pRight = new BinaryTreeNode;
    pRoot->m_pRight->m_nValue = 3;
    pRoot->m_pLeft->m_pLeft = new BinaryTreeNode;
    pRoot->m_pLeft->m_pLeft->m_nValue = 4;
    pRoot->m_pRight->m_pLeft = NULL;
    pRoot->m_pLeft->m_pRight = new BinaryTreeNode;
    pRoot->m_pLeft->m_pRight->m_nValue = 5;
    pRoot->m_pRight->m_pRight = new BinaryTreeNode;
    pRoot->m_pRight->m_pRight->m_nValue = 6;
    pRoot->m_pRight->m_pRight->m_pLeft = NULL;
    pRoot->m_pRight->m_pRight->m_pRight = NULL;
    pRoot->m_pLeft->m_pRight->m_pLeft = new BinaryTreeNode;
    pRoot->m_pLeft->m_pRight->m_pLeft->m_nValue = 7;
    pRoot->m_pLeft->m_pRight->m_pRight = NULL;
    pRoot->m_pLeft->m_pRight->m_pLeft->m_pLeft = NULL;
    pRoot->m_pLeft->m_pRight->m_pLeft->m_pRight = NULL;

    test("test1", pRoot, true);
}

static void test2()
{
    BinaryTreeNode* pRoot = new BinaryTreeNode;
    pRoot->m_nValue = 1;
    pRoot->m_pLeft = new BinaryTreeNode;
    pRoot->m_pLeft->m_nValue = 2;
    pRoot->m_pRight = new BinaryTreeNode;
    pRoot->m_pRight->m_nValue = 5;
    pRoot->m_pRight->m_pLeft = NULL;
    pRoot->m_pRight->m_pRight = NULL;

    pRoot->m_pLeft->m_pLeft = new BinaryTreeNode;
    pRoot->m_pLeft->m_pLeft->m_nValue = 3;
    pRoot->m_pLeft->m_pRight = NULL;
    pRoot->m_pLeft->m_pLeft->m_pLeft = NULL;
    pRoot->m_pLeft->m_pLeft->m_pRight = new BinaryTreeNode;
    pRoot->m_pLeft->m_pLeft->m_pRight->m_nValue = 4;
    pRoot->m_pLeft->m_pLeft->m_pRight->m_pLeft = NULL;
    pRoot->m_pLeft->m_pLeft->m_pRight->m_pRight = NULL;

    test("test2", pRoot, false);
}

int main()
{
    test1();
    test2();
    return 0;
}
