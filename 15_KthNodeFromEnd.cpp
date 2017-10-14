#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void CreateList(int* nums, int length, ListNode** pHead)
{
    if (nums == NULL || length <= 0)
        return;

    *pHead = NULL;
    for (int i = length - 1; i >= 0; i--)
    {
        ListNode* pNewNode = new ListNode;
        pNewNode->m_nValue = nums[i];
        pNewNode->m_pNext = *pHead;
        *pHead = pNewNode;
    }
}

ListNode* FindKthToTail(ListNode* head, int k)
{
    if (head == NULL || k <= 0)
        return NULL;
    ListNode* p = head;
    ListNode* q = head;
    int cnt = 0;
    while (p->m_pNext !=  NULL)
    {
        p = p->m_pNext;

        if (cnt < k)
            cnt++;

        if (cnt == k)
            q = q->m_pNext;
    }
    if (cnt < k)
        return NULL;
    return q;
}

int main()
{
    int nums1[] = {1,2,3,4,5,6,7,8,9};
    int len1 = 9;
    int k1 = 4;
    ListNode* head1;
    CreateList(nums1, len1, &head1);
    ListNode* r1 = FindKthToTail(head1, k1);
    if (r1 != NULL) cout << r1->m_nValue << endl;

    int nums2[] = {1,2,3};
    int len2 = 3;
    int k2 = 4;
    ListNode* head2;
    CreateList(nums2, len2, &head2);
    ListNode* r2 = FindKthToTail(head2, k2);
    if (r2 != NULL) cout << r2->m_nValue << endl;

    int* nums3 = NULL;
    ListNode* head3 = NULL;
    int k = 0;
    ListNode* r3 = FindKthToTail(head3, 0);
    if (r3 != NULL) cout << r3->m_nValue << endl;
 
    return 0;
}
