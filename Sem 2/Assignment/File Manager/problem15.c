// Write a C program that uses fscanf function to read integer values from a file, computes the square of each integer value and places the resultant values in a different file.

#include <stdio.h>

int main()
{
    FILE *fp1 = fopen("integer.txt", "r");
    if (fp1 == NULL)
    {
        printf("Cannot open integer.txt\n");
        return 1;
    }
    
    FILE *fp2 = fopen("square.txt", "w");
    if (fp2 == NULL)
    {
        printf("Cannot open square.txt\n");
        fclose(fp1);
        return 1;
    }
    
    int num;
    while (fscanf(fp1, "%d", &num) == 1)
        fprintf(fp2, "%d\n", num * num);

    fclose(fp1);
    fclose(fp2);

    printf("Successfully Written Squares in square.txt.\n");
    
    return 0;
}