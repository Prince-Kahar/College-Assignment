/*
Write a program to read the file created in problem8 and compute and print the total value of all the five products.
*/

#include <stdio.h>

struct product
{
    int pcode;
    float cost;
    int quantity;
};

int main()
{
    FILE *fp;

    struct product p;
    float total = 0;
    char str[1000];

    fp = fopen("product", "r");
    if (fp == NULL)
    {
        printf("File is Not Open\n");
        return 1;
    }
    else
        printf("File is Opened Successfully\n");

    fgets(str, sizeof(str), fp); // Skip header line
    while (fscanf(fp, "%d %f %d", &p.pcode, &p.cost, &p.quantity) != EOF)
        total += (p.cost * p.quantity);

    fclose(fp);
    printf("Total value of all five products = %.2f\n", total);

    return 0;
}