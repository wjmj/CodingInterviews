#include <iostream>
#include <stdexcept>

using namespace std;

int Min(int* nums, int length)
{
    if (nums == NULL || length <= 0)
        throw new runtime_error("argument invalid");

    int low = 0, high = length;
    while (low < high)
    {
        int m = (low + high) / 2;
        if (m > 0 && nums[m] < nums[m-1])
            return nums[m];
        else if (nums[m] >=  nums[0])
            low = m + 1;
        else
            high = m;
    }
}

int main()
{
    int nums1[] = {3,4,5,1,2};
    cout << Min(nums1, 5) << endl;
    
    int nums2[] = {4,5,1,2,3};
    cout << Min(nums2, 5) << endl;

    int nums3[] = {5,1,2,3,4};
    cout <<Min(nums3, 5) << endl;
    return 0;
}
