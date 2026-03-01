#include <stdio.h>
#include <stdbool.h>
#include <math.h>
float find1(float u, int x)
{
    float save = 1;
    for (int i = 0; i <= x; i++)
    {
        save *= (u + i);
    }
    return save;
}
float find2(int i)
{
    float save = 1.0;
    while (i > 0)
    {
        save *= i;
        i--;
    }
    return save;
}
int main()
{
    printf("enter total no of data\n");
    int n;
    float find;
    scanf("%d", &n);
    printf("enter the value of x for which you want the value of y:");
    scanf("%f", &find);
    float arr[2][100];
    int i, j;
    printf("\nenter the value\nX----Y\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &arr[0][i], &arr[1][i]);
    }
    int x = 0, y = 1;
    int save = n;
    bool b1 = true;
    int q = n - 1;

    while (q > 0)
    {
        arr[1][i] = (arr[1][y] - arr[1][x]);
        i++;
        x++;
        y++;
        if (y == save)
        {
            x++;
            y++;
            save += q;
            q--;
        }
    }
    //  for(int a1=0;a1<i;a1++)
    //  {
    //     printf(" %0.f ",arr[1][a1]);
    //  }
    int g1 = n - 1;
    for (int a1 = 0; a1 < n; a1++)
    {
        printf(" %0.f ", arr[1][a1]);
        int df = a1 + n - 1;
        int sd = n - 1;
        while (sd > g1)
        {
            printf(" %0.f ", arr[1][df]);
            sd--;
            df += sd;
        }
        printf("\n");
        g1--;
    }
    float u;
    u = ((find - arr[0][n - 1]) / fabs(arr[0][1] - arr[0][2]));
    printf("U---%f\n", u);
    float sum = arr[1][n - 1];
    int index = (n - 1) + (n - 1);
    int asd = n - 2;
    for (int qw = 0; qw < n && index < i; qw++)
    {
        float t = find1(u, qw);
        float p = find2(qw + 1);
        sum += ((t * arr[1][index]) / p);
        index += asd;
        asd--;
    }

    printf("\n----- %f ", sum);
    return 0;
}
