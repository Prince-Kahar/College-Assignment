// Design and code an interactive modular program that will use functions to a matrix of m by n size, compute column averages and row averages, and then print the entire matrix with averages shown in respective rows and columns.

#include <stdio.h>

void average_of_row_and_col(int m, int n, int matrix[][n], float row_averages[], float column_averages[])
{
    for (int i = 0; i < m; i++)
    {
        row_averages[i] = 0;
        for (int j = 0; j < n; j++)
            row_averages[i] += matrix[i][j];
        row_averages[i] /= n;
    }

    for (int j = 0; j < n; j++)
    {
        column_averages[j] = 0;
        for (int i = 0; i < m; i++)
            column_averages[j] += matrix[i][j];
        column_averages[j] /= m;
    }
}

void display(int m, int n, int matrix[][n], float row_averages[], float column_averages[])
{
    printf("\nMatrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d  ", matrix[i][j]);
        printf("\n");
    }

    printf("\nRow Average : ");
    for (int i = 0; i < m; i++)
        printf("%.2f  ", row_averages[i]);

    printf("\nColumn Averages : ");
    for (int j = 0; j < n; j++)
        printf("%.2f  ", column_averages[j]);
    printf("\n");
}

int main()
{
    int m, n;

    printf("Enter the size of the matrix (m and n): ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    float row_averages[m];
    float column_averages[n];

    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Enter Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }

    average_of_row_and_col(m, n, matrix, row_averages, column_averages);
    display(m, n, matrix, row_averages, column_averages);

    return 0;
}