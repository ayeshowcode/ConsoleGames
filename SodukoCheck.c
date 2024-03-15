#include <stdio.h>
int boxcheck(int arr[9][9]);
int rowcheck(int arr[9][9]);
int colcheck(int arr[9][9]);
int main()
{
    int arr[9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                     {4, 5, 6, 7, 8, 9, 1, 2, 3},
                     {7, 8, 9, 1, 2, 3, 4, 5, 6},
                     {2, 3, 4, 5, 6, 7, 8, 9, 1},
                     {5, 6, 7, 8, 9, 1, 2, 3, 4},
                     {8, 9, 1, 2, 3, 4, 5, 6, 7},
                     {3, 4, 5, 6, 7, 8, 9, 1, 2},
                     {6, 7, 8, 9, 1, 2, 3, 4, 5},
                     {9, 1, 2, 3, 4, 5, 6, 7, 8}};

    if (boxcheck(arr) == 1 && rowcheck(arr) == 1 && colcheck(arr) == 1)
    {
        printf("Valid!!");
    }
    else
    {
        printf("Invalid!!");
    }
    return 0;
}

int boxcheck(int arr[9][9])
{
    int c[10] = {0};
    for (int i = 0; i < 3; i += 3)
    {
        for (int j = 0; j < 3; j += 3)
        {
            for (int k = i; k < i + 3; k++)
            {
                for (int l = i; l < j + 3; l++)
                {
                    c[arr[k][l]]++;
                }
            }
            for (int m = 1; m < 10; m++)
            {
                if (c[m] != 1)
                {
                    return 0;
                }
            }
            for (int n = 0; n < 10; n++)
            {
                c[n] = 0;
            }
        }
    }
    return 1;
}

int rowcheck(int arr[9][9])
{
    int c[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int k = 1; k < 10; k++)
        {
            c[k] = 0;
        }
        for (int j = 0; j < 9; j++)
        {
            c[arr[i][j]]++;
        }
        for (int l = 1; l < 10; l++)
        {
            if (c[l] != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int colcheck(int arr[9][9])
{
    int c[10] = {0};
    for (int j = 0; j < 9; j++)
    {
        for (int k = 1; k < 10; k++)
        {
            c[k] = 0;
        }
        for (int i = 0; i < 9; i++)
        {
            c[arr[i][j]]++;
        }
        for (int l = 1; l < 10; l++)
        {
            if (c[l] != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}