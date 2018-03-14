#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    if (array.empty())
        return 0;
    int len = array.size();
    int max = 0;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (sum <= 0)
            sum = array[i];
        else
            sum += array[i];
        
        if (i == 0)
            max = sum;

        if ((i > 0) && (sum > max))
            max = sum;
    }

    return max;
}

int main()
{
    int n1[] = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> nums1(n1, n1 + sizeof(n1)/sizeof(int));
    cout << FindGreatestSumOfSubArray(nums1) << endl;

}
