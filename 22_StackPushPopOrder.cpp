#include <iostream>
#include <stack>

using namespace std;

bool isPopOrder(const int* pPush, const int* pPop, int length)
{
    if (pPush == NULL || pPop == NULL || length <= 0)
        return false;
    if (length <= 2)
        return true;
    stack<int> s;
    int k = 0;
    for (int i = 0; i < length; i++)    
    {
        if (!s.empty() && s.top() == pPop[i])
        {
            s.pop();
            continue;
        }
        while (k < length && pPush[k] != pPop[i])
        {
            s.push(pPush[k]);
            k++;
        }
        if (k >= length)
            return false;
        k++;
    }
    return true;
        
}
    
int main()
{
    int push1[] = {1, 2, 3, 4, 5};
    int pop1[] = {4, 5, 3, 2, 1};
    int pop2[] = {5, 3, 4, 2 ,1};
    cout << boolalpha << isPopOrder(push1, pop1, 5) << endl;
    cout << isPopOrder(push1, pop2, 5) << endl;
    return 0;
}
