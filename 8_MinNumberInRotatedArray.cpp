#include <iostream>
#include <stdexcept>

using namespace std;

int MinInorder(int* nums, int low, int high)
{
    int result = nums[low];
    for (int i = low+1; i <= high; i++)
    {
        if (nums[i] < result)
            result = nums[i];
    }
    return result;
}

int Min(int* nums, int length)
{
    if (nums == NULL || length <= 0)
        throw new runtime_error("argument invalid");

    int low = 0, high = length - 1;
    int m = 0;
    while (nums[low] >= nums[high])
    {
        if (high - low == 1)
        {
            m = high;
            break;
        }

        int m = (low + high) / 2;

        if (nums[low] == nums[m] && nums[high] == nums[m])
            return MinInorder(nums, low, high);

        else if (nums[m] >= nums[low])
            low = m;
        else
            high = m;
    }

    return nums[m];
}

int main()
{
    int nums1[] = {3,4,5,1,2};
    cout << Min(nums1, 5) << endl;
    
    int nums2[] = {4,5,1,2,3};
    cout << Min(nums2, 5) << endl;

    int nums3[] = {5,1,2,3,4};
    cout <<Min(nums3, 5) << endl;

    int nums4[] = {1,2,3,4,5};
    cout << Min(nums4, 5) << endl;

    int nums5[] = {1,0,1,1,1};
    cout << Min(nums5, 5) << endl;

    int nums6[] = {1,1,1,0,1};
    cout << Min(nums5, 5) << endl;

    return 0;
}
