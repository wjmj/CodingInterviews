#include <iostream>
#include <vector>

using namespace std;

int MoreThanHalfNum(vector<int> array)
{
    if (array.empty())
        return 0;
    int len = array.size();
    int c = 1;
    int num = array[0];
    for (int i = 1; i < len; i++)
    {
        if (num == array[i])
            c++;
        else
        {
            c--;
            if (c == 0)
            {
                num = array[i];
                c = 1;
            }
        }
    }

    if (c <= 0) return 0;
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (array[i] == num)
            cnt++;
    if (cnt > len/2) return num;
    return 0;
}

int main()
{
    int mnums1[] = {1,2,3,4,2,2,5,2,2};
    vector<int> nums1(mnums1, mnums1+sizeof(mnums1) / sizeof(int));
    cout << MoreThanHalfNum(nums1) << endl;

    int mnums2[] = {6,1,7,1,8,1,1,9};
    vector<int> nums2(mnums2, mnums2+sizeof(mnums2)/sizeof(int));
    cout << MoreThanHalfNum(nums2) << endl;

    int mnums3[] = {1,2,3,4};
    vector<int> nums3(mnums3, mnums3 + sizeof(mnums3) / sizeof(int));
    cout << MoreThanHalfNum(nums3) << endl;
}
