#include<stdio.h>
#include<math.h>
#define X(x) (1/(1+(x)*(x)))
int main()
{
    int n;
    float a,b,h;
    printf("enter the no of levels:");
    scanf("%d",&n);
    printf("enter the upper and lower value: ");
   scanf("%f %f",&a,&b);
   float arr[2][n];
   h=(fabs(a-b)/(n-1));
   printf("h:%f\n",h);
   arr[0][0]=b;
   for(int i=1;i<n;i++)
   {
    arr[0][i]=(h+arr[0][i-1]);

   }
   float mul3=0.0,other=0.0,save;
   for(int i=0;i<n;i++)
   {
    arr[1][i]=X(arr[0][i]);
    printf("X:%f  Y:%f\n",arr[0][i],arr[1][i]);
    if(i!=0&&i!=n-1)
    {
        if(i%3==0)
    {
        mul3+=arr[1][i];
    }
    else{
        other+=arr[1][i];
    }
    }
   }
   save=((3*h)/8)*((arr[1][0]+arr[1][n-1])+2*(mul3)+3*(other));
   printf("\nans--%f",save);
   return 0;
}