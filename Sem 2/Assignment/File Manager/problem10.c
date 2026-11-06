/*
Rewrite the program developed in problem8 to store the details in a random access file and print the details of alternate products from the file.
Modify the program so that it can output the details of a product when its code is specified interactively.
*/

#include <stdio.h>

struct product
{
    int product_code;
    float cost;
    int quantity;
} p;

int main()
{
    FILE *fp;

    int i, n, search_code, found = 0;

    fp = fopen("product.dat", "wb+");
    if (fp == NULL)
    {
        printf("File not opened\n");
        return 1;
    }

    /* Product Details */

    printf("How many Product Details You have to Enter : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter product code: ");
        scanf("%d", &p.product_code);
        printf("Enter cost: ");
        scanf("%f", &p.cost);
        printf("Enter quantity: ");
        scanf("%d", &p.quantity);

        fwrite(&p, sizeof(p), 1, fp);
    }

    /* Alternate product details */

    printf("\nAlternate product details:\n");
    rewind(fp);

    for (i = 0; i < n; i += 2)
    {
        fseek(fp, i * sizeof(p), SEEK_SET);
        fread(&p, sizeof(p), 1, fp);

        printf("Code: %d  Cost: %.2f  Quantity: %d\n", p.product_code, p.cost, p.quantity);
    }

    /* search by product code */

    printf("\nEnter product code to search: ");
    scanf("%d", &search_code);

    rewind(fp);

    while (fread(&p, sizeof(p), 1, fp))
    {
        if (p.product_code == search_code)
        {
            printf("\nProduct Found:");
            printf("\nCode: %d", p.product_code);
            printf("\nCost: %.2f", p.cost);
            printf("\nQuantity: %d\n", p.quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct not found\n");
    fclose(fp);

    return 0;
}