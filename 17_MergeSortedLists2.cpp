#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* Merge(ListNode* head1, ListNode* head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->m_nValue < head2->m_nValue)
    {
        head1->m_pNext = Merge(head1->m_pNext, head2);
        return head1;
    }
    else
    {
        head2->m_pNext = Merge(head1, head2->m_pNext);
        return head2;
    }
}
    
void PrintList(ListNode* head)
{
    if (head != NULL)
    {
        ListNode* p = head;
        while (p != NULL)
        {
            cout << p->m_nValue << endl;
            p = p->m_pNext;
        }
        cout << endl;
    }
}

void CreateList(int* nums, int length, ListNode** pHead)
{
    *pHead = NULL;
    if (nums == NULL || length <= 0)
        return;
    
    for (int i = length-1; i >= 0; i--)
    {
        ListNode* newNode = new ListNode;
        newNode->m_nValue = nums[i];
        newNode->m_pNext = *pHead;
        *pHead = newNode;
    }
}

int main()
{
    int nums1[] = {1, 3, 5, 7};
    int nums2[] = {2, 4, 6, 8};
    ListNode* head1;
    ListNode* head2;
    CreateList(nums1, 4, &head1);
    CreateList(nums2, 4, &head2);
    ListNode* head12 = Merge(head1, head2);
    PrintList(head12);

    int nums3[] = {2};
    int nums4[] = {1, 3};
    ListNode* head3;
    ListNode* head4;
    CreateList(nums3, 1, &head3);
    CreateList(nums4, 2, &head4);
    ListNode* head34 = Merge(head3, head4);
    PrintList(head34);

    int nums5[] = {3};
    int nums6[] = {5};
    ListNode* head5;
    ListNode* head6;
    CreateList(nums5, 1, &head5);
    CreateList(nums6, 1, &head6);
    ListNode* head56 = Merge(head5, head6);
    PrintList(head56);

    int nums7[] = {3, 4};
    int* nums8 = NULL;
    ListNode* head7;
    ListNode* head8;
    CreateList(nums7, 2, &head7);
    CreateList(nums8, 0, &head8);
    ListNode* head78 = Merge(head7, head8);
    PrintList(head78);

    int* nums9 = NULL;
    int* nums10 = NULL;
    ListNode* head9;
    ListNode* head10;
    CreateList(nums9, 0, &head9);
    CreateList(nums10, 0, &head10);
    ListNode* head90 = Merge(head9, head10);
    PrintList(head90);

    return 0;
}
