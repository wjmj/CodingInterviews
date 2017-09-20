/*************************************************************************
	> File Name: 3_FindInPartiallySortedMatrix.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Sep 2017 07:50:14 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

bool isInMatrix(int nums[][4], int rowNum, int colNum, int x)
{
    if (nums == NULL)
        return false;
    int i = 0 , j = colNum - 1;
    while (i < rowNum && j > -1)
    {
        if (nums[i][j] == x)
            return true;
        else if (nums[i][j] > x)
            j--;
        else
            i++;
    }

    return false;
}

int main()
{
    int nums[4][4] = {{1,2,4,8}, {2,4,6,9}, {4,7,8,10}, {6,8,9,11}};
    cout << boolalpha << isInMatrix(nums, 4, 4, 7) << endl;

    return 0;
}
