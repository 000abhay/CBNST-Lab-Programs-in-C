#include<stdio.h>
#include<math.h>
void swap_rows(float arr[3][4], int r1, int r2, int c)
{
    printf("\n");
    for (int i = 0; i < c; i++)
    {
        float temp = arr[r1][i];
        arr[r1][i] = arr[r2][i];
        arr[r2][i] = temp;
    }
}

void jordan(float arr[3][4])
{
    int r=3,c=4;
 for (int sr = 0, sc = 0; sr < r && sc < c - 1; sr++, sc++) // c-1 for augmented column
    {
        // printf("\nsr---%d......sc----%d\n",sr,sc);
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
                continue;  // Skip if no non-zero pivot is found
            }
        }
        float pivot = arr[sr][sc];
        for (int j = 0; j < c; j++)
        {
            arr[sr][j] /= pivot;
        }
        for (int i = 0; i < r; i++)
        {
            // print_matrix(arr,r,c);
            if (i != sr)
            {
                float factor = arr[i][sc];
                for (int j = 0; j < c; j++)
                {
                    arr[i][j] -= factor * arr[sr][j];
                }
            }
        }
        //print_matrix(arr, r, c);
       // printf("\n");
    }
}
int main()
{
    int n;
    printf("enter the total of data\n");
    scanf("%d",&n);
    float arr[n][7];
    printf("enter the data points\n");
    float x=0.0,y=0.0,xy=0.0,x2=0.0,x3=0.0,x4=0.0,x2y=0.0;
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&arr[i][0],&arr[i][1]);
         arr[i][5]=(arr[i][0]*arr[i][1]);
         arr[i][2]=(powf(arr[i][0],2));
         arr[i][3]=(powf(arr[i][0],3));
         arr[i][4]=(powf(arr[i][0],4));
         arr[i][6]=(arr[i][2]*arr[i][1]);
         x+=arr[i][0];
         y+=arr[i][1];
         xy+=arr[i][5];
         x2+=arr[i][2];
         x3+=arr[i][3];
         x4+=arr[i][4];
         x2y+=arr[i][6];


    }
    printf("x:%f y:%f x2:%f x3:%f x4:%f xy:%f x2y:%f\n",x,y,x2,x3,x4,xy,x2y);
    float ans[3][4];
    ans[0][0]=n;
    ans[0][1]=x;
    ans[0][2]=x2;
    ans[0][3]=y;
    
    ans[1][0]=x;
    ans[1][1]=x2;
    ans[1][2]=x3;
    ans[1][3]=xy;

    ans[2][0]=x2;
    ans[2][1]=x3;
    ans[2][2]=x4;
    ans[2][3]=x2y;
    jordan(ans);
    float a,b,c;
    a=ans[0][3];
    b=ans[1][3];
    c=ans[2][3];
    printf("\na:%f b:%f c:%f  equation is %f+%fx+%fx^2",a,b,c,a,b,c);
    

    return 0;
}