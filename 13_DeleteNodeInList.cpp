#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (pListHead != NULL && *pListHead != NULL && pToBeDeleted != NULL)
    {
        if (*pListHead == pToBeDeleted)
        {
            *pListHead = pToBeDeleted->m_pNext;
            delete pToBeDeleted;
            pToBeDeleted = NULL;
        }
        else if (pToBeDeleted->m_pNext == NULL)
        {
            ListNode* p= *pListHead;
            while (p -> m_pNext != pToBeDeleted)
                p = p ->m_pNext;
            p->m_pNext = NULL;
            delete pToBeDeleted;
            pToBeDeleted = NULL;
        }
               
        else
        {
            ListNode* next = pToBeDeleted->m_pNext;
            pToBeDeleted->m_nValue = next->m_nValue;
            pToBeDeleted->m_pNext = next->m_pNext;
            delete next;
        }
    }
}

void CreateList(ListNode** pHead, int* nums, int length)
{
    if (nums == NULL || length <= 0)
        return;

    *pHead = NULL;
    for (int i = length - 1; i >= 0; i--)
    {
        ListNode* pNew = new ListNode;
        pNew->m_nValue = nums[i];
	pNew->m_pNext = *pHead;
        *pHead = pNew;
    }
}

void PrintList(ListNode* head)
{
    ListNode* p = head;
    while (p != NULL)
    {
        cout << p->m_nValue << endl;
        p = p->m_pNext;
    }
    cout << endl;
}

int main()
{
    int nums1[] = {1, 2, 3, 4, 5, 6};
    ListNode* head1;
    CreateList(&head1, nums1, 6);
    PrintList(head1);
    DeleteNode(&head1, head1->m_pNext->m_pNext);
    PrintList(head1);

    DeleteNode(&head1, head1);
    PrintList(head1);
    return 0;
}
