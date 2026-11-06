// Write a function that can be called to find the largest element of an m by n matrix.

#include <stdio.h>

int largest_element(int m, int n, int matrix[m][n])
{
    int largest_element = matrix[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] > largest_element)
                largest_element = matrix[i][j];
    return largest_element;
}

int main()
{
    int m, n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Enter Element [%d][%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    printf("The largest element in the matrix is: %d\n", largest_element(m, n, matrix));

    return 0;
}