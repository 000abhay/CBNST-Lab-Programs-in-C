#include<stdio.h>
#define X(x) ((x)*(x)*(x))
#include<math.h>

int main()
{
    int n;
    float a,b,h;
    printf("enter the no of level\n");
    scanf("%d",&n);
    printf("enter the lower and upper value\n");
     scanf("%f %f",&a,&b);
     h=(fabs(a-b))/(n-1);
     printf("h--%f\n",h);
     float arr[2][n];
     arr[0][0]=b;
     for(int i=1;i<n;i++)
     {
      arr[0][i]=(h+arr[0][i-1]);
     }
     float sum=0.0,save;
     for(int i=0;i<n;i++)
     {
        arr[1][i]=X(arr[0][i]);
        if(i!=0&&i!=n-1)
        {
            sum+=arr[1][i];
        }
        //printf("X:%f---Y:%f\n",arr[0][i],arr[1][i]);
     }

    save=(h/2)*((arr[1][0]+arr[1][n-1])+(2*sum));
    printf("\nyour value is:%f",save);
     
                                                          
     return 0;
}
