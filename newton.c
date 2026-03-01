#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (x*x*x)-(4*x)-9;
}
float fx(float x)
{
    return 3*(x*x)-4;
}
int main()
{
    float x0,x1,x,error;
    printf("enter the value of x0 and x1\n");
    while(1)
    {
    scanf("%f %f",&x0,&x1);
        
        if(f(x0)*f(x1)<0)
        {
            break;
        }
        printf("enter valid root\n");
    }
printf("enter the errro\n");
scanf("%f",&error);
int i=1;
while(1)
{
    
    
    x=x0-(f(x0)/fx(x0));
    printf("root value %f at %d ith iteration\n ",x,i++);
    if(f(x)<error)
    {
        printf("function value %f  lie at %f root",f(x),x);
    break;
    }
    x0=x;
    

}
return 0;
}
