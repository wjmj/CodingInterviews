#include <iostream>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

void PrintListReversingly(ListNode* head)
{
    if (head == NULL)
        return;

    PrintListReversingly(head->m_pNext);
    cout << head->m_nKey << endl;   
}


void CreateList(ListNode** pHead, int* nums, int length)
{
    for (int i = length-1; i >= 0; i--)
    {
        ListNode* pNew = new ListNode();
        pNew->m_nKey = nums[i];
        pNew->m_pNext = *pHead;
        *pHead = pNew;
    }
}
int main()
{
    int nums[] = {1,2,4,5,3,8,7,6};
    ListNode* head = NULL;
    CreateList(&head, nums, 8);
    PrintListReversingly(head);
}
