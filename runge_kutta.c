//4th order
#include<stdio.h>
#include<math.h>
#define X(x,y) (y-x)
float K1(float x0,float y0,float h)
{
    return (h*X(x0,y0));
}
float K2(float x0,float y0,float h,float k1)
{
   return ( h*(X((x0+h/2),(y0+k1/2))));
}
float K4(float x0,float y0,float h,float k1)
{
    return (h*(X(x0+h,y0+k1)));
}
float delta_y(float x0,float y0,float h)
{
    float k1=K1(x0,y0,h);
    float k2=K2(x0,y0,h,k1);
    float k3=K2(x0,y0,h,k2);
    float k4=K4(x0,y0,h,k3);

    float qw=(k1+(2*k2)+(2*k3)+(k4));
    qw=(1.0/6.0)*qw;
    printf("K1:%f K2:%f K3:%f k4:%f  qw:%f\n",k1,k2,k3,k4,qw);
    return qw;
    
    //return t;
}
int main()
{
    float x0,y0,x1,xn,y1,h;
    printf("enter the intial value of x0 and y0:");
    scanf("%f %f",&x0,&y0);
    printf("enter the value of x1 for y1 to finding it:");
     scanf("%f",&xn);
     printf("enter the value of h spacing:");
     scanf("%f",&h);
   x1=x0+h;
   int n=(xn/h);
   for(int i=0;i<n;i++)
   {
    float asd=delta_y(x0,y0,h);
   // printf("delta:%f  ",asd);
   y1=y0+asd;
   y0=y1;
   x0+=h;
   }
   printf("\nans y:%f  ",y1);

     return 0;

}