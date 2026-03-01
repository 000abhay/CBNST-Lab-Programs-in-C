/*#include <stdio.h>
#include <math.h>

// Function whose root we are trying to find
float fun(float x) {
    return cos(x)-3*x+1;
}

// Function for fixed-point iteration (ensure this is correctly derived for your problem)
float fun2(float x) {
    return -(sin(x)/3.0);
}

// Function to update x in fixed-point iteration
float fun3(float x) {
    return   (1.0/3)*(cos(x)+1);
}

int main() {
    float x0, x1, err;
    
    // Input for initial guess
    while (1) {
        printf("Enter the initial value of x0: ");
        scanf("%f", &x0);
        if (fun2(x0) < 1) {
            printf("Case satisfied for initial value x0 = %f\n", x0);
            break;
        }
        printf("Wrong interval---try again\n");
    }

    // Input for allowed error
    printf("Enter the allowed error: ");
    scanf("%f", &err);

    if (err <= 0) {
        printf("Error must be a positive number.\n");
        return 1; // Exit with error code
    }

    int i = 1;
    while (1) {
        x1 = fun3(x0);
        printf("Iteration %d: x1 = %f\n", i, x1);
        
        // Check if the function value at x1 is within the acceptable error
        if (fabs(fun(x1)) < err) {
            printf("\nThe root of the equation is: %f\n", x1);
            break;
        }

        x0 = x1;
        i++;
    }
    
    return 0;
}
#include<stdio.h>
#include<math.h>
float f( float x)
{ return ((x*x)*exp(-x/2))-1;}
int main()
{
    float x,x0,x1,err;
    printf("enter the value of x0 and x1\n");
    scanf("%f %f",&x0,&x1);
while(1)
{
    if(f(x0)*f(x1)<0)
    {
        printf("roots lie between x0-%f and x1-%f:\n",x0,x1);
        break;
    }
    printf("error invalid--try again\n");
}
printf("enter the allowed error\n");
scanf("%f",&err);
int i=1;
while(1)
{
   x=x1-((x1-x0)/(f(x1)-f(x0)))*f(x1);
   printf("value of root %f and function is %f at %d iteration\n",x,f(x),i);
   if(fabs(f(x))<err)
   {
    printf("final root value is %f at %d iteration\n",x,i);
    break;
   }
   x0=x1;
   x1=x;
i++;
}#include <stdio.h>

void swap_rows(float arr[][100], int r1, int r2, int c)
{
    for (int i = 0; i < c; i++)
    {
        float temp = arr[r1][i];
        arr[r1][i] = arr[r2][i];
        arr[r2][i] = temp;
    }
}

void p(float arr[][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.0f ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int r, c;
    printf("Enter the row and column size\n");
    scanf("%d %d", &r, &c);
    
    float arr[r][100]; // Define with a constant size for the second dimension
    
    printf("Enter the matrix elements\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    printf("Upper triangular matrix\n");

    // Perform Gaussian elimination
    for (int sr = 0, sc = 0; sr < r && sc < c; sr++, sc++)
    {
        // Check if pivot is zero
        if (arr[sr][sc] == 0)
        {
            // Find a row below where the pivot is non-zero
            int swap_row = sr + 1;
            while (swap_row < r && arr[swap_row][sc] == 0)
                swap_row++;

            if (swap_row < r)  // If found a non-zero pivot row, swap it
            {
                swap_rows(arr, sr, swap_row, c);
            }
            else
            {
                // If no suitable row is found, skip this column
                continue;
            }
        }

        float b = arr[sr][sc];
        for (int i = sr + 1; i < r; i++)
        {
            float a = arr[i][sc];
            for (int j = sc; j < c; j++)
            {
                arr[i][j] = arr[i][j] - ((a / b) * arr[sr][j]);
            }
        }
    }

    p(arr, r, c);
    return 0;
}

    return 0;
}*/
#include <stdio.h>


void swap_rows(float arr[][100], int r1, int r2, int c)
{
    printf("\n");
    for (int i = 0; i < c; i++)
    {
        float temp = arr[r1][i];
        arr[r1][i] = arr[r2][i];
        arr[r2][i] = temp;
    }
}


void p(float arr[][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.2f  ", arr[i][j]);
        }
        printf("\n");
    }
}
void lower(float arr[][100],int r,int c)
{
for (int sr = r-1, sc = c-2; sr >=0 && sc >=0; sr--, sc--)
    {
        if (arr[sr][sc] == 0)
        {
           
            int swap_row = sr -1;
            while (swap_row >=0 && arr[swap_row][sc] == 0)
                swap_row--;

            if (swap_row >=0)  
            {
                swap_rows(arr, sr, swap_row, c);
            }
            else
            {
               
                continue;
            }
        }

        
        float b = arr[sr][sc];
        for (int i = sr - 1; i >=0; i--)
        {
            float a = arr[i][sc];
            p(arr,r,c);
            for (int j = c-1; j >=0; j--)
            {
                arr[i][j] = arr[i][j] - ((a / b) * arr[sr][j]);
            }
        }
    }
    p(arr,r,c);
    }
int main()
{
    int r, c;
    printf("Enter the row and column size\n");
    scanf("%d %d", &r, &c);
    
    float arr[r][100]; 
    
   
    printf("Enter the matrix elements\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    printf("your matrix is\n");
    p(arr,r,c);
    printf("\nUpper triangular matrix:\n");
int x=0;
    if(arr[0][0]!=1)
    {
    for(int i=1;i<r;i++)
    {
    
        if(arr[i][0]==1)
        {
             x=1;
            swap_rows(arr,i,i-1,c);
            break;
        }
    }
    }
    if(x==0)
    {
        int y=arr[0][0];
        for(int i=0;i<c;i++)
        {
            arr[0][i]=(arr[0][i]/y);
        }
    }
    for (int sr = 0, sc = 0; sr < r && sc < c; sr++, sc++)
    {
        if (arr[sr][sc] == 0)
        {
           
            int swap_row = sr + 1;
            while (swap_row < r && arr[swap_row][sc] == 0)
                swap_row++;

            if (swap_row < r)  
            {
                swap_rows(arr, sr, swap_row, c);
            }
            else
            {
               
                continue;
            }
        }

        
        float b = arr[sr][sc];
        for (int i = sr + 1; i < r; i++)
        {
            float a = arr[i][sc];
            p(arr,r,c);
            for (int j = sc; j < c; j++)
            {
                arr[i][j] = arr[i][j] - ((a / b) * arr[sr][j]);
            }
        }
    }
    p(arr,r,c);
    printf("upper\n");
    lower(arr,r,c);
printf("after\n");
   
    p(arr, r, c);

   
    float save[r]; 
for(int i=0;i<r;i++)
{
    save[i]=(arr[i][c-1]/arr[i][i]);
}
   
    for (int i = 0; i < r; i++)
    {
        printf("x%d = %.2f\n", i + 1, save[i]);
    }

    return 0;
//GAUSS ELEMINATION METHOD
    // for (int i = r - 1; i >= 0; i--)
    // {
    //     save[i] = arr[i][c - 1]; 

       
    //     for (int j = i + 1; j < c - 1; j++)
    //     {
    //         save[i] -= arr[i][j] * save[j];
    //     }

        
    //     save[i] /= arr[i][i];
    // }

    
}
/*#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (3*x)-cos(x)-1;
}
float fx(float x)
{
    return 3+sin(x);
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
}*/
