/*
Write a program to create a sequential file that could store details about five products.
Details include product code, cost and number of items available and are provided through keyboard.
*/

#include <stdio.h>

struct product
{
    int code;
    float cost;
    int quantity;
}p;

int main()
{
    FILE *fp;
    
    int i,n;

    fp = fopen("product", "w");

    if (fp == NULL)
    {
        printf("File is Not Open\n");
        return 1;
    }
    else
        printf("File is Opened Successfully\n");

    fprintf(fp, "Code\t\t\tCost\t\t\tQuantity\n");

    printf("How many Product Details You have to Enter : ");
    scanf("%d",&n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter details of product %d\n", i);

        printf("Product code: ");
        scanf("%d", &p.code);
        printf("Cost: ");
        scanf("%f", &p.cost);
        printf("Number of items available: ");
        scanf("%d", &p.quantity);

        fprintf(fp, "%-15d %-15.2f %-15d\n", p.code, p.cost, p.quantity);
    }

    fclose(fp);

    printf("\nProduct details stored successfully\n");
    return 0;
}