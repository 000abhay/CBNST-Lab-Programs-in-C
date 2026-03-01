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

void print_matrix(float arr[][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.2f  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gauss_jordan(float arr[][100], int r, int c)
{
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
        print_matrix(arr, r, c);
        printf("\n");
    }
}

int main()
{
    int r, c;
    printf("Enter the row and column size (including augmented column):\n");
    scanf("%d %d", &r, &c);
    
    float arr[r][100]; // matrix declaration with row size dynamic, column fixed
   
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    printf("Initial matrix:\n");
    print_matrix(arr, r, c);
    printf("\nGauss-Jordan Elimination steps:\n");
    gauss_jordan(arr, r, c);
    printf("\nMatrix:\n");
    print_matrix(arr, r, c);
    printf("\nSolution:\n");
    for (int i = 0; i < r; i++)
    {
        printf("x%d = %.2f\n", i + 1, arr[i][c - 1]);
    }

    return 0;
}
