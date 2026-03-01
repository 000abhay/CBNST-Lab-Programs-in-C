#include<stdio.h>
#include<stdbool.h>
#include<math.h>
float find1(float u,int x)
{
    float save=1;
    for(int i=0;i<=x;i++)
    {
      save*=(u-i);
    }
    return save;
}
int find2(int i)
{
    int save=1;
    while(i>0)
    {
        save*=i;
        i--;
    }
    return save;
}
int main()
{
    printf("enter total no of data\n");
    int n;
    float find;
    scanf("%d",&n);
     printf("enter the value of x for which you want the value of y:");
     scanf("%f",&find);
    float arr[2][100];
    int i,j;
    printf("\nenter the value\nX----Y\n");
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&arr[0][i],&arr[1][i]);
    }
    int x=0,y=1;
    int save=n;
bool b1=true;
int q=n-1;

     while (q>0)
     {
        arr[1][i]=(arr[1][y]-arr[1][x]);
        i++;x++;y++;
      if(y==save)
      {
        x++;
        y++;
        save+=q;
        q--;
      }
    
     }
     
     printf("\ninterpolation table\n");
   int g1=1;
     for(int a1=0;a1<n;a1++)
     {
       printf(" %.0f ",arr[1][a1]);
       int sa=n;
       int df=a1+sa;
       while(sa>g1)
       {
        printf(" %0.f ",arr[1][df]);
        sa--;
         df+=sa;
       }
       printf("\n");
       g1++;
     }
    float a=100000;
   float save2=arr[0][0];
     x=0;
     int index;
    while(x<n)
    {
       if(a>fabs(arr[0][x]-find))
       {
        a=fabs(arr[0][x]-find);
          save2=arr[0][x];
          index=x;
       }
       else{
        break;
       }
       x++;
    }
   // printf("@@%f",save2);
    float u=(find-save2)/(fabs(arr[0][0]-arr[0][1]));
    float sum=arr[1][index];
    printf("\n Value of U:%f\n",u);
    q=n;
    int track=index;
  //  printf("!!%f %f",u,sum);
    y=1;
    while(y<n&&track<i)
    {
   track+=q;
   q--;
   float we =find1(u,y-1);
   float ye=find2(y);
  // printf("\n---%f %f----\n",we,ye);
sum+=((we)*(arr[1][track]))/ye;

y++;


    }
    printf(" \n when X=%.1f then Y=%f",find,sum);
    return 0;

}