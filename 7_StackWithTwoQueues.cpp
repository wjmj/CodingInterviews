#include <iostream>
#include <queue>
#include <exception>

using namespace std;

template <typename T>
class CStack
{
public:
    void push(const T& node);
    T pop();

private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T>
void CStack<T>::push(const T& node)
{
    if (!queue2.empty())
    {
        queue2.push(node);
        return;
    }
   
    queue1.push(node);
}

template <typename T>
T CStack<T>::pop()
{
    T temp;
    if (!queue1.empty())
    {
        int len = queue1.size();
        for (int i = 0; i < len-1;i++)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        temp = queue1.front();
        queue1.pop();
    }
    else
    {
        int len = queue2.size();
        for (int i = 0; i < len - 1; i++)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        temp = queue2.front();
        queue2.pop();
    }

    return temp;
}
    
     
int main()
{
    CStack<int> s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    return 0;
}
