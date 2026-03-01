#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap_rows(int arr[][100], int r, int c, int row1, int row2) {
    for (int j = 0; j < c; j++) {
        int temp = arr[row1][j];
        arr[row1][j] = arr[row2][j];
        arr[row2][j] = temp;
    }
}

int check_diagonal_dominance(int arr[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        int diagonal = abs(arr[i][i]);
        int sum_other_elements = 0;
        for (int j = 0; j < c - 1; j++) {
            if (i != j) {
                sum_other_elements += abs(arr[i][j]);
            }
        }
        if (diagonal <= sum_other_elements) {
            
            return i; 
        }
    }
    return -1; 
}

float fun1(int arr[][100], int r, int c, float a, float b) {
    return (arr[0][c-1] + (-arr[0][1] * a) + (-arr[0][2] * b)) / arr[0][0];
}

float fun2(int arr[][100], int r, int c, float a, float b) {
    return (arr[1][c-1] + (-arr[1][0] * a) + (-arr[1][2] * b)) / arr[1][1];
}

float fun3(int arr[][100], int r, int c, float a, float b) {
    return (arr[2][c-1] + (-arr[2][0] * a) + (-arr[2][1] * b)) / arr[2][2];
}

int main() {
    int r, c;
    printf("Enter row and column size (should be 3x4 for a system of 3 equations): ");
    scanf("%d %d", &r, &c);

    if (r != 3 || c != 4) {
        printf("Invalid matrix size. Please enter a 3x4 matrix.\n");
        return 1;
    }

    int arr[3][100];
    printf("Enter the array elements (3x4 matrix):\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    
    int non_dominant_row = check_diagonal_dominance(arr, r, c);
    while (non_dominant_row != -1) {
       
        int swapped = 0;
        for (int i = 0; i < r; i++) {
            if (i != non_dominant_row) {
              
                swap_rows(arr, r, c, non_dominant_row, i);
                swapped = 1;
                break;
            }
        }
        if (!swapped) {
            printf("The system cannot be made diagonally dominant. Exiting.\n");
            return 1;
        }
        non_dominant_row = check_diagonal_dominance(arr, r, c);
    }

    float x1 = 0.0, x2 = 0.0, x3 = 0.0;
    float error, prev_x1, prev_x2, prev_x3;
    printf("Enter the tolerance value: ");
    scanf("%f", &error);

    int max_iterations = 1000, iter = 0;
    do {
        prev_x1 = x1;
        prev_x2 = x2;
        prev_x3 = x3;

        x1 = fun1(arr, r, c, x2, x3);
        x2 = fun2(arr, r, c, x1, x3);
        x3 = fun3(arr, r, c, x1, x2);

        iter++;
        printf("value of x:%.02f ,y:%.02f ,z:%.02f at %d iteration\n",x1,x2,x3,iter);
        if (iter > max_iterations) {
            printf("Reached maximum iterations without convergence.\n");
            break;
        }
    } while (fabs(x1 - prev_x1) > error || fabs(x2 - prev_x2) > error || fabs(x3 - prev_x3) > error);

    printf("\nConverged after %d iterations.\n", iter);
    printf("x1: %f x2: %f x3: %f\n", x1, x2, x3);

    return 0;
}
