#include <iostream>

using namespace std;

const int BASENUM = 100;
const int NUM = 5000;
const int INCNUM = 50;

template <class T>
class MinStack
{
private:
    T* values;
    T* minValues;
    int length;
    int size;
    int top;
public:
    MinStack();
    ~MinStack();
    T min();
    void push(T x);
    void pop();
};

template <class T>
MinStack<T>::MinStack()
{
    values = new T[BASENUM];
    minValues = new T[BASENUM];
    length = 0;
    size = BASENUM;
    top = -1;
}

template <class T>
MinStack<T>::~MinStack()
{
    if (values != NULL)
        delete [] values;
    if (minValues != NULL)
        delete [] minValues;
}

template <class T>
T MinStack<T>::min()
{
    if (length != 0)
        return minValues[top];
    return -1;
}

template <class T>
void MinStack<T>::push(T x)
{
    if (length+1 >= size)
    {
        if (size < NUM)
        {
            T* temp = new T[2*size];
            for (int i = 0; i < length;i++)
                temp[i] = values[i];
            delete [] values;
            values = temp;
            size *= 2;

            T* temp2 = new T[2*size];
            for (int i = 0; i < length; i++)
            temp2[i] = minValues[i];
            delete [] minValues;
            minValues = temp2;
        }
        else
        {
            T* temp = new T[size + INCNUM];
            for (int i = 0; i < length; i++)
                temp[i] = values[i];
            delete [] values;
            values = temp;
            size += INCNUM;

            T* temp2 = new T[size + INCNUM];
            for (int i = 0; i < length; i++)
                temp2[i] = minValues[i];
            delete [] minValues;
            minValues = temp2;
        }
    }
    values[++top] = x;
    minValues[top] = x;
    if (length > 0 && x > minValues[top-1])
        minValues[top] = minValues[top-1];
    length++;
}

template <class T>
void MinStack<T>::pop()
{
    if (length == 0)
        return;
    length--;
    top--;
}
    
int main()
{
    MinStack<int> s1;
    for (int i = 10; i >= 1;i--)
        s1.push(i);
    for (int i = 0; i < 10; i++)
    {
        cout << s1.min() << endl;
        s1.pop();
    }
    cout << endl;

    MinStack<int> s2;
    for (int i = 0; i < 10;i++)
        s2.push(i);
    for (int i = 0; i < 10; i++)
    {
        cout << s2.min() << endl;
        s2.pop();
    }
    return 0;
}
