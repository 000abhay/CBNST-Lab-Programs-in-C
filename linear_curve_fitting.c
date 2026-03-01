#include<stdio.h>
#include<math.h>
void swap_rows(float arr[][3], int r1, int r2, int c)
{
    printf("\n");
    for (int i = 0; i < c; i++)
    {
        float temp = arr[r1][i];
        arr[r1][i] = arr[r2][i];
        arr[r2][i] = temp;
    }
}

void jordan(float arr[2][3])
{
    int r=2,c=3;
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
    float arr[n][4];
    printf("enter the data points\n");
    float x=0.0,y=0.0,xy=0.0,x2=0.0;
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&arr[i][0],&arr[i][1]);
         arr[i][2]=(arr[i][0]*arr[i][1]);
         arr[i][3]=(powf(arr[i][0],2));
         x+=arr[i][0];
         y+=arr[i][1];
         xy+=arr[i][2];
         x2+=arr[i][3];

    }
    printf("x:%f y:%f xy:%f x2%f\n",x,y,xy,x2);
    float ans[2][3];
    ans[0][0]=n;
    ans[0][1]=x;
    ans[0][2]=y;

    ans[1][0]=x;
    ans[1][1]=x2;
    ans[1][2]=xy;
    float a,b;
     jordan(ans);
     a=ans[0][2];
     b=ans[1][2];
     printf("\na:%f b:%f  equation is y=%f+%fx",a,b,a,b);
    
    
    return 0;
}