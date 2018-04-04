#include <iostream>

using namespace std;

int getNumberOfK(int* nums, int length, int k)
{
    if ((nums == NULL) || (length <= 0))
        return 0;

    int left = 0;
    int right = length - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (left+right)/2;
        if (nums[mid] == k)
            break;
        else if (nums[mid] > k)
            right = mid-1;
        else
            left = mid+1;
    }

    if (left > right)
        return 0;
    int i = mid;
    while ((i >= 0) && (nums[i] == nums[mid]))
        i--;
    int j = mid;
    while ((j < length) && (nums[j] == nums[mid]))
        j++;
    
    return j-i-1;
}
        

//======================Test Code==================
static void test(const char* testName, int* nums, int length, int k, int expected)
{
    cout << testName << " Begins: ";
    int count = getNumberOfK(nums, length, k);
    if (count == expected)
        cout << "Passed." << endl;
    else
        cout << "Failed." << endl;
}

static void test1()
{
    int nums[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int length = 8;
    int k = 3;
    test("test1", nums, length, k, 4);
}

static void test2()
{
    int* nums = NULL;
    int length = 0;
    int k = 1;
    test("test2", nums, length, k, 0);
}

int main()
{
    test1();
    test2();
    
    return 0;
}
