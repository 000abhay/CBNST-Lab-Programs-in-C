#include <stdio.h>
void fun1(float arr[][2], float find, int n, int x, float *a, float *b)
{
    float sum = 1.0, sum2 = 1.0;
    for (int i = 0; i < n; i++)
    {
        if (i != x)
        {
            sum *= (find - arr[i][0]);
            sum2 *= (arr[x][0] - arr[i][0]);
        }
    }
    *a = sum;
    *b = sum2;
}
int main()
{
    int n;
    printf("enter the no of points\n");
    scanf("%d", &n);
    float arr[n][2];
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &arr[i][0], &arr[i][1]);
    }
    float find;
    printf("enter the find value\n");
    scanf("%f", &find);
    for (int i = 0; i < n; i++)
    {
        float a, b;
        fun1(arr, find, n, i, &a, &b);
        sum += (((arr[i][1]) * a) / b);
    }
    printf(" \nyour value is:%f", sum);
    return 0;
}