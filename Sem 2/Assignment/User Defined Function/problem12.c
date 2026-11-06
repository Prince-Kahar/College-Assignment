/*
Write a function that can be called to compute the product of two matrices of size m by n and n by m.
The main function provides the values for m and n and two matrices.
*/

#include <stdio.h>

void element(int *element, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            printf("Enter Element [%d][%d] : ", i, j);
            scanf("%d", &element[i * col + j]);
        }
}

void matrices_product(int m, int n, int matrix1[][n], int matrix2[][m], int result[][m])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += matrix1[i][k] * matrix2[k][j];
            result[i][j] = sum;
        }
}

int main()
{
    int rows1, cols1, rows2, cols2;

    while (1)
    {
        printf("Enter the number of rows and columns for Matrix 1: ");
        scanf("%d %d", &rows1, &cols1);
        printf("Enter the number of rows and columns for Matrix 2: ");
        scanf("%d %d", &rows2, &cols2);

        if (cols1 != rows2)
        {
            printf("Error: matrix 1 column cannot equal matrix 2 rows\n\n");
            continue;
        }

        int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

        printf("Enter the elements of the first matrix:\n");
        element(&matrix1[0][0], rows1, cols1);

        printf("Enter the elements of the second matrix:\n");
        element(&matrix2[0][0], rows2, cols2);

        matrices_product(rows1, cols1, matrix1, matrix2, result);
        printf("Product of the matrices:\n");
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
        return 0;
    }
}