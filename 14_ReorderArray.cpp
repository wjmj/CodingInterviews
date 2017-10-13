#include <iostream>

using namespace std;

void ReorderArray(int* nums, int length)
{
    if (nums != NULL && length > 0)
    {
        int i = 0, j = length -1;
        while (i <= j)
        {
            while ((i < length) && (nums[i]%2 == 1))
                i++;
            while ((j >= 0) && (nums[j]%2 == 0))
                j--;
            if ((i < length) && (j >= 0) && (i < j))
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main()
{
    int nums1[] = {1,4,5,2,3,6,7,9,8};
    int length = 9;
    ReorderArray(nums1, length);
    for (int i = 0; i < length; i++)
        cout << nums1[i] << endl;
    return 0;
}
