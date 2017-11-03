#include <iostream>

using namespace std;

bool VerifySequenceOfBST(int* sequence, int length)
{
    if (sequence == NULL || length <= 0)
        return false;

    int root_value = sequence[length-1];
    int left_length = 0;
    while (sequence[left_length] < root_value)
        left_length++;
    for (int i = left_length; i < length-1; i++)
        if (sequence[i] < root_value)
            return false;
    bool left = true;
    bool right = true;
    if (left_length > 0)
        left = VerifySequenceOfBST(sequence, left_length);
    if (length - left_length - 1 > 0)
        right = VerifySequenceOfBST(sequence + left_length, length-left_length-1);
    return left && right;
}

int main()
{
    int s[] = {5, 7, 6, 9, 11, 10, 8};
    cout << boolalpha << VerifySequenceOfBST(s, 7) << endl;
    int s2[] = {9, 6, 5, 7, 11, 10, 8};
    cout << VerifySequenceOfBST(s2, 7) << endl;
    return 0;
}
