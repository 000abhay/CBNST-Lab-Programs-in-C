// #include<stdio.h>
// #include<math.h>
// void p(float arr[][100], int r, int c)
// {
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             printf("%.2f  ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }
// void swap(float arr[][100],int sr,int swap_row,int c)
// {
//     for(int i=0;i<c;i++)
//     {
//          float temp =arr[sr][i];
//         arr[sr][i]=arr[swap_row][i];
//         arr[swap_row][i]=temp;
//     }
// }
// void check(float arr[][100],int sr,int sc,int r,int c)
// {
    
//     int swap_row=sr+1;
//     while(swap_row<r&&arr[swap_row][sc]==0)
//     {
//         swap_row++;
//     }
//     if(swap_row<r)
//     {
//         swap(arr,sr,swap_row,c);
//     }
    

// }
// int main()
// {
//     int r, c;
//     printf("Enter the row and column size\n");
//     scanf("%d %d", &r, &c);
    
//     float arr[r][100]; 
    
   
//     printf("Enter the matrix elements\n");
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             scanf("%f", &arr[i][j]);
//         }
//     }
//     printf("your matrix is\n");
//     p(arr,r,c);
//     printf("\nUpper triangular matrix:\n");
    
//     for(int sr=0,sc=0;sr<r&&sc<c;sr++,sc++)
//     {
//         if(arr[sr][sc]==0.0)
//         {
//         check(arr,sr,sc,r,c);
//         }
//         float b=arr[sr][sc];
//         for(int i=sr+1;i<r;i++)
//         {
//             float a=arr[i][sc];
//             for(int j=sc;j<c;j++)
//             {
//                 arr[i][j]-=((a/b)*arr[sr][j]);
//             }
//         }
//     }
//     p(arr,r,c);
//     float save[r];
//     for(int i=r-1;i>=0;i--)
//     {
//         save[i]=arr[i][c-1];
//         for(int j=i+1;j<r;j++)
//         {
//             save[i]-=(arr[i][j]*save[j]);
//         }
//         save[i]/=arr[i][i];
//     }
//     for(int i=0;i<r;i++)
//     {
//         printf("  %f  ",save[i]);
//     }
//     return 0;
// }
