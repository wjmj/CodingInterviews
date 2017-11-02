#include <iostream>

using namespace std;

void PrintMatrixClockwisely(int** nums, int cols, int rows)
{
    if (nums == NULL || cols <= 0 || rows <= 0)
        return;
    int iter_nums = cols;
    if (rows < cols)
        iter_nums = rows;
    iter_nums = (iter_nums + 1)/2;
    int k = 1;
    while (k <= iter_nums)
    {
        int i = k-1;
        int j = k-1;
        while (j <= (cols-k))
        {
            cout << nums[i][j] << " ";
            j++;
        }
        j--;
        i++;
        while(i <= rows-k)
        {
            cout << nums[i][j] << " ";
            i++;
        }
        i--;
        j--;
        while (j >= k-1)
        {
            cout << nums[i][j] << " ";
            j--;
        }
        j++;
        i--;
        while (i >= k)
        {
            cout << nums[i][j] << " ";
            i--;
        }
        k++;
    }
    cout << endl;

}

int main()
{
    int k;
    int** nums1 = new int* [2];
    for (int i = 0; i < 2; i++)
        nums1[i] = new int[3];
    k = 1;
    for (int i = 0; i < 2;i++)
    for (int j = 0;j < 3;j++)
        nums1[i][j] = k++;
    PrintMatrixClockwisely(nums1, 3, 2);
    
    int** nums2 = new int* [4];
    for (int i = 0; i < 4;i++)
        nums2[i] = new int[4];
    k = 1;
    for (int i = 0; i < 4;i++)
    for (int j = 0; j < 4;j++)
        nums2[i][j] = k++;

    PrintMatrixClockwisely(nums2, 4, 4);

    return 0;
}
