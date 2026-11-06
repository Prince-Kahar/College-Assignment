// Write a function that pointers to add two matrices and to return the resultant matrix to the calling function

#include <stdio.h>

void input(int *arr, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            printf("Enter array%d[%d][%d] : ", n, i, j);
            scanf("%d", &arr[i * col + j]);
        }
}

void add_two_matrices(int *ptr, int *ptr2, int *ans, int row, int col)
{
    for (int i = 0; i < row * col; i++)
        *(ans + i) = *(ptr + i) + *(ptr2 + i);
}

int main()
{
    while (1)
    {
        int i, j, row1, col1, row2, col2;
        printf("Enter Matrix 1 Row and Column : ");
        scanf("%d %d", &row1, &col1);
        printf("Enter Matrix 2 Row and Column : ");
        scanf("%d %d", &row2, &col2);

        if (row1 == row2 && col1 == col2)
        {
            int matrix1[row1][col1], matrix2[row2][col2], add[row1][col1];
            input(*matrix1, row1, col1, 1);

            printf("\n");
            input(*matrix2, row2, col2, 2);

            add_two_matrices(*matrix1, *matrix2, *add, row1, col1);
            printf("Addition of the given Matrices is \n");

            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                    printf("%d\t", add[i][j]);
                printf("\n");
            }
        }
        else
        {
            printf("Error! Matrix Order is different \n\n");
            continue;
        }
        break;
    }
    return 0;
}