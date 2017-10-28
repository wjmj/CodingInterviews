#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

bool IsSubtree(BinaryTreeNode* aRoot, BinaryTreeNode* bRoot)
{
    if (bRoot == NULL)
        return true;
    if (aRoot == NULL)
        return false;
    if (aRoot->m_nValue == bRoot->m_nValue)
        return IsSubtree(aRoot->m_pLeft, bRoot->m_pLeft) && IsSubtree(aRoot->m_pRight, bRoot->m_pRight);
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
        bool res = IsSubtree(aRoot->m_pLeft, bRoot->m_pLeft) && IsSubtree(aRoot->m_pRight, bRoot->m_pRight);
        if (res)
            return true;
    }
    return HasSubtree(aRoot->m_pLeft, bRoot) || HasSubtree(aRoot->m_pRight, bRoot);    
}

int main()
{
    BinaryTreeNode* root1 = new BinaryTreeNode;
    root1->m_nValue = 8;
    root1->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_nValue = 8;
    root1->m_pRight = new BinaryTreeNode;
    root1->m_pRight->m_nValue = 7;
    root1->m_pRight->m_pLeft = NULL;
    root1->m_pRight->m_pRight = NULL;
    root1->m_pLeft->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_pLeft->m_nValue = 9;
    root1->m_pLeft->m_pLeft->m_pLeft = NULL;
    root1->m_pLeft->m_pLeft->m_pRight = NULL;
    root1->m_pLeft->m_pRight = new BinaryTreeNode;
    root1->m_pLeft->m_pRight->m_nValue = 2;
    root1->m_pLeft->m_pRight->m_pLeft = new BinaryTreeNode;
    root1->m_pLeft->m_pRight->m_pLeft->m_nValue = 4;
    root1->m_pLeft->m_pRight->m_pLeft->m_pLeft = NULL;
    root1->m_pLeft->m_pRight->m_pLeft->m_pRight = NULL;
    root1->m_pLeft->m_pRight->m_pRight = new BinaryTreeNode;
    root1->m_pLeft->m_pRight->m_pRight->m_nValue = 7;
    root1->m_pLeft->m_pRight->m_pRight->m_pLeft = NULL;
    root1->m_pLeft->m_pRight->m_pRight->m_pRight = NULL;

    BinaryTreeNode* root2 = new BinaryTreeNode;
    root2->m_nValue = 8;
    root2->m_pLeft = new BinaryTreeNode;
    root2->m_pLeft->m_nValue = 9;
    root2->m_pLeft->m_pLeft = NULL;
    root2->m_pLeft->m_pRight = NULL;
    root2->m_pRight = new BinaryTreeNode;
    root2->m_pRight->m_nValue = 2;
    root2->m_pRight->m_pLeft = NULL;
    root2->m_pRight->m_pRight = NULL;
 
    cout << boolalpha << HasSubtree(root1, root2) << endl;
    
    BinaryTreeNode* root3 = new BinaryTreeNode;
    root3->m_nValue = 8;
    root3->m_pLeft = new BinaryTreeNode;
    root3->m_pLeft->m_nValue = 8;
    root3->m_pRight = new BinaryTreeNode;
    root3->m_pRight->m_nValue = 7;
    root3->m_pRight->m_pLeft = NULL;
    root3->m_pRight->m_pRight = NULL;
    root3->m_pLeft->m_pLeft = new BinaryTreeNode;
    root3->m_pLeft->m_pLeft->m_nValue = 9;
    root3->m_pLeft->m_pLeft->m_pLeft = NULL;
    root3->m_pLeft->m_pLeft->m_pRight = NULL;
    root3->m_pLeft->m_pRight = new BinaryTreeNode;
    root3->m_pLeft->m_pRight->m_nValue = 2;
    root3->m_pLeft->m_pRight->m_pLeft = NULL;
    root3->m_pLeft->m_pRight->m_pRight = NULL;

    cout << HasSubtree(root3, root2) << endl;

    BinaryTreeNode* root4 = new BinaryTreeNode;
    root4->m_nValue = 8;
    root4->m_pLeft = new BinaryTreeNode;
    root4->m_pLeft->m_nValue = 9;
    root4->m_pRight = new BinaryTreeNode;
    root4->m_pRight->m_nValue = 2;
    root4->m_pRight->m_pLeft = NULL;
    root4->m_pRight->m_pRight = NULL;
    root4->m_pLeft->m_pLeft = new BinaryTreeNode;
    root4->m_pLeft->m_pLeft->m_nValue = 4;
    root4->m_pLeft->m_pLeft->m_pLeft = NULL;
    root4->m_pLeft->m_pLeft->m_pRight = NULL;
    root4->m_pLeft->m_pRight = new BinaryTreeNode;
    root4->m_pLeft->m_pRight->m_nValue = 7;
    root4->m_pLeft->m_pRight->m_pLeft = NULL;
    root4->m_pLeft->m_pRight->m_pRight = NULL;

    cout << HasSubtree(root4, root2) << endl;

    BinaryTreeNode* root5 = new BinaryTreeNode;
    root5->m_nValue = 8;
    root5->m_pLeft = new BinaryTreeNode;
    root5->m_pLeft->m_nValue = 9;
    root5->m_pLeft->m_pLeft = NULL;
    root5->m_pLeft->m_pRight = NULL;
    root5->m_pRight = new BinaryTreeNode;
    root5->m_pRight->m_nValue = 7;
    root5->m_pRight->m_pLeft = NULL;
    root5->m_pRight->m_pRight = NULL;

    cout << HasSubtree(root5, root2) << endl;

    return 0;
}
