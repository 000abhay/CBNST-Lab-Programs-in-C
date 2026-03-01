#include<stdio.h>
#include<math.h>
float X(float x,float y)
{
    return ((y-x)/(y+x));
}
int main()
{
    int n;
    printf("enter the no of no of levels:");
    scanf("%d",&n);
    float y0,x0,x1;
     printf("enter the x0 and y0 value and x1 for finding the value for y1:");
     scanf("%f",&x0);
     scanf("%f",&y0);
     scanf("%f",&x1);
    float arr[n];
    float h=(x1/(n-1));
    printf("%f\n",h);
    arr[0]=x0;
    for(int i=1;i<n;i++)
    {
        arr[i]=(h+arr[i-1]);
        printf("x:%f\n",arr[i-1]);
    }
    float save;
    for(int i=0;i<n-1;i++)
    {

        save=y0+(h*X(arr[0],y0));
       // printf("save:%f fun:%f\n",save,X(arr[i],y0));
        y0=save;

    }
   printf("\nans:%f",save);
    return 0;
}