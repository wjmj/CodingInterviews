#include <iostream>

using namespace std;

int merge(int* data, int* tmp, int start, int mid, int end)
{
    int i = mid;
    int j = end;
    int k = end;
    int sum = 0;
    while ((i >= start) && (j > mid))
    {
        if (data[i] > data[j])
        {
            tmp[k] = data[i];
            sum += j - mid;
            i--;
        }

        else
        {
            tmp[k] = data[j];
            j--;
        }
        k--;
    }

    while (i >= start)
    {
        tmp[k] = data[i];
        k--;
        i--;
    }

    while (j > mid)
    {
        tmp[k] = data[j];
        j--;
        k--;
    }

    for (int index= start; index <= end; index++)
        data[index] = tmp[index];

    return sum;
}
       
int inversePairsCore(int* data, int* tmp, int start, int end) 
{
    int sum = 0;
    if (start < end)
    {
        int mid = (start+end)/2;
        int leftSum = inversePairsCore(data, tmp, start, mid);
        int rightSum = inversePairsCore(data, tmp, mid+1, end);
        int mergeSum = merge(data, tmp, start, mid, end);

        sum = leftSum + rightSum + mergeSum;
    }

    return sum;
}

int inversePairs(const int* nums, int length)
{
    if (nums == NULL || length <= 0)
        return 0;
    int* data = new int[length];
    for (int i = 0; i < length; i++)
        data[i] = nums[i];
    int* tmp = new int[length];
    return inversePairsCore(data, tmp, 0, length-1);
}

//=================Test code=========================
static void test(const char* testName, const int* nums, int length, int expected)
{
    cout << testName << " " << "Begins: ";
    int count  = inversePairs(nums, length);
    if (count == expected)
        cout << "Passed." << endl;
    else
        cout << "Failed" << endl;
}

static void test1()
{
    int nums[] = {7, 5, 6, 4};
    test("test1", nums, 4, 5);
}

static void test2()
{
    int* nums = NULL;
    test("test2", nums, 0, 0);
}

static void test3()
{
    int nums[] = {1,2,3,4};
    test("test3", nums, 4, 0);
}
    
int main()
{
    test1();
    test2();
    test3();

    return 0;
}
