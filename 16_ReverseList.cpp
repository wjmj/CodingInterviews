#include <iostream>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
}; 

ListNode* ReverseList(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;
    ListNode* newHead = NULL;
    ListNode* cursor = pHead;
    while (cursor != NULL)
    {
        pHead = pHead->m_pNext;
        cursor->m_pNext = newHead;
        newHead = cursor;
        cursor = pHead;
    }
    return newHead;
}

void CreateList(int* nums, int length, ListNode** pHead)
{
    if (nums == NULL || length <= 0)
        return;

    *pHead = NULL;
    for (int i = length -1; i >= 0; i--)
    {
        ListNode* pNewNode = new ListNode;
        pNewNode->m_nKey = nums[i];
        pNewNode->m_pNext = *pHead;
        *pHead = pNewNode;
    }
}

void PrintList(ListNode* head)
{
    if (head != NULL)
    {
        ListNode* p = head;
        while (p != NULL)
        {
            cout << p->m_nKey << endl;
            p = p->m_pNext;
        }
    }
    cout << endl;
}

int main()
{
    int nums1[] = {1,2,3,4,5};
    int len1 = 5;
    ListNode* head1;
    CreateList(nums1, 5, &head1);
    PrintList(head1);
    head1 = ReverseList(head1);
    PrintList(head1);

    int nums2[] = {1};
    int len2 = 1;
    ListNode* head2;
    CreateList(nums2, len2, &head2);
    PrintList(head2);
    head2 = ReverseList(head2);
    PrintList(head2);

    int *nums3 = NULL;
    int len3 = 0;
    ListNode* head3 = NULL;
    head3 = ReverseList(head3);
    PrintList(head3);
    return 0;
}
