#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructBinaryTree(int preorder[], int inorder[], int len)
{
    BinaryTreeNode* head = NULL;
    if (preorder != NULL && inorder != NULL && len > 0)
    {
        BinaryTreeNode* pNew = new BinaryTreeNode();
        pNew->m_nValue = preorder[0];
        pNew->m_pLeft = NULL;
        pNew->m_pRight = NULL;
        head = pNew;
        int i = 0;
        for (; i < len; i++)
        {
            if (inorder[i] == preorder[0])
                break;
        }
        if (i > 0)
            head->m_pLeft = ConstructBinaryTree(preorder+1, inorder, i);
        if (i < len-1)
            head->m_pRight = ConstructBinaryTree(preorder + i + 1, inorder + i + 1,len- i - 1);
    }
    
    return head;
}

void print(BinaryTreeNode* head)
{
    if (head != NULL)
    {
        cout << head->m_nValue << " ";
        cout << "{" << " ";
        print(head->m_pLeft);
        cout << "}" << " ";
        cout << "{" << " ";
        print(head->m_pRight);
        cout << "}" << " ";
    }
}

int main()
{
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode* head = ConstructBinaryTree(preorder, inorder, 8);
    print(head);
    return 0;
}
