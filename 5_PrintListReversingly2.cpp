#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int mValue;
    ListNode* pNext;
};

void PrintListReversingly(ListNode* head)
{
    if (head != NULL)
    {
        stack<int> s;
        ListNode* p = head;
        while (p)
        {
            s.push(p->mValue);
            p = p->pNext;
        }

        
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
    }

    
}
void CreateList(ListNode** pHead, int* nums, int length)
{
    if (nums != NULL && length > 0)
    {
        *pHead = NULL;
        for (int i = length - 1; i >= 0; i--)
        {
            ListNode* pNew = new ListNode();
            pNew->mValue = nums[i];
            pNew->pNext = *pHead;
            *pHead = pNew;
        }
    }
}
int main()
{
    ListNode* head1 = NULL;
    int nums1[] = {1};
    CreateList(&head1, nums1, 1);
    PrintListReversingly(head1);

    ListNode* head2;
    int nums2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    CreateList(&head2, nums2, 8);
    PrintListReversingly(head2);
}
