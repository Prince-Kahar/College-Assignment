/*
Add a function to the program of problem 9 that accepts two vectors as input parameter and return the addition of two vectors.
*/

#include <stdio.h>

struct vector
{
    int arr[100];
    int size;
} v1, v2, add;

void create_vector(struct vector *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", &v->arr[i]);
    }
}

int addition_of_vectors(struct vector *v1, struct vector *v2, struct vector *addition)
{
    if (v1->size != v2->size)
        return 0;

    addition->size = v1->size;

    for (int i = 0; i < v1->size; i++)
        addition->arr[i] = v1->arr[i] + v2->arr[i];
    return 1;
}

void display_vector(struct vector v)
{
    printf("( ");
    for (int i = 0; i < v.size; i++)
    {
        printf("%d", v.arr[i]);
        if (i != v.size - 1)
            printf(", ");
    }
    printf(" )\n");
}

int main()
{
    printf("Enter First Vector Size: ");
    scanf("%d", &v1.size);

    printf("Enter Second Vector Size: ");
    scanf("%d", &v2.size);

    if (v1.size != v2.size)
    {
        printf("\nVector addition not possible. Sizes are different.\n");
        return 0;
    }
    printf("\nEnter First Vector : \n");
    create_vector(&v1, v1.size);

    printf("\nEnter Second Vector : \n");
    create_vector(&v2, v2.size);

    addition_of_vectors(&v1, &v2, &add);
    printf("Addition of Vectors:\n   ");
    display_vector(v1);
    printf(" + ");
    display_vector(v2);
    printf("--------------------\n");
    printf(" = ");
    display_vector(add);
    return 0;
}