#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int go(float arr[][10], float save, int n)
{
    float lowest = 10000;
    int index, i = 0;
    while (i < n)
    {
        if (fabs(arr[i][0] - save) < lowest)
        {
            lowest = fabs(arr[i][0] - save);
            index = i;
        }
        i++;
    }
    return index;
}
int factorial(int x)
{
    int save = 1;
    while (x)
    {
        save *= x;
        x--;
    }
    return save;
}
float fun(float u, int p)
{
    bool b1 = false, b2 = false;
    float x = u;
    int a = 1;
    for (int i = 0; i < p; i++)
    {
        if (b1 & b2)
        {
            b1 = false;
            b2 = false;
            a++;
        }
        if (i % 2 == 0)
        {
            b1 = true;
            x *= (u - a);
        }
        else
        {
            b2 = true;
            x *= (u + a);
        }
    }
    return x;
}
int main()
{
    int n, i;
    printf("enter the no of data points\n");
    scanf("%d", &n);
    float arr[n][10];
    printf("enter the data X----Y\n");
    i = 0;
    while (i < n)
    {
        scanf("%f %f", &arr[i][0], &arr[i][1]);
        i++;
    }
    int p1, p2, p3, limit = n, col = 2;
    p1 = 0, p2 = 1, p3 = 0;
    while (limit > 1)
    {
        arr[p3][col] = (arr[p2][col - 1] - arr[p1][col - 1]);
        p3++;
        p1++;
        p2++;
        if (p2 >= limit)
        {
            p1 = 0;
            p2 = 1;
            p3 = 0;
            limit--;
            col++;
        }
    }
    limit = n;
    int save = col;
    for (i = 0; i < n; i++, col--)
    {
        for (int j = 0; j < col; j++)
        {
            printf("    %f    ", arr[i][j]);
        }
        printf("\n");
    }
    float u, find;
    printf("enter the finding value\n");
    scanf("%f", &find);
    int index = go(arr, find, n);
    u = ((find - arr[index][0]) / fabs(arr[0][0] - arr[1][0]));
    i = 0;
    float sum = arr[index][1];
    int f = 1;
    col = 2;
    while (i < n - 1 && index > -1)
    {
        float q = fun(u, f - 1);
        float w = (float)factorial(f);
        sum = (sum + arr[index][col] * q / w);
        if (col % 2 == 0)
        {
            index--;
        }
        f++;
        col++;
        i++;
    }
    printf("\nyour value is:%f", sum);
    return 0;
}