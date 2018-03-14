#include <iostream>
#include <vector>
#include <functional>
#include <set>

using namespace std;

vector<int> GetKLeastNums(vector<int> array, int k)
{
    vector<int> result;
    int len = array.size();
    if (len == 0 || k <= 0)
        return result;

    multiset<int, greater<int> > s;
    multiset<int, greater<int> >::iterator it;
    
    for (int i = 0; i < len; i++)
    {
        if (s.size() < k)
        {
            s.insert(array[i]);
        }
            
        else
        {
            it = s.begin();
            if (*it > array[i])
            {
                s.erase(it);
                s.insert(array[i]);
            }
        }
    }

    for (it = s.begin(); it != s.end(); it++)
    {
        result.push_back(*it);
    }
    
    return result;
}

int main()
{
    int n1[] = {4,5,1,6,2,7,3,8};
    vector<int> nums1(n1, n1 + sizeof(n1)/sizeof(int));

    vector<int> res1 = GetKLeastNums(nums1, 4);
    vector<int> res2 = GetKLeastNums(nums1, 1);

    for (int i = 0; i < res1.size(); i++)
        cout << res1[i] << " ";
    cout << endl;

    for (int i = 0; i < res2.size(); i++)
        cout << res2[i] << " ";
    cout << endl;
}
