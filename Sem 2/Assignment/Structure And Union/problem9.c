/*
Define a structure to represent a vector ( a series of integer values ) and write a modular program to perform the following tasks:
    A. To create a vector
    B. To modify the value of a given element
    C. To multiply by a scalar value
    D. To displaty the vector in the form
       ( 10, 20, 30, ..... ..)
*/

#include <stdio.h>

struct vector
{
    int arr[100];
    int size;
}v;

void create_vector(struct vector *v)
{
    printf("Enter size of vector: ");
    scanf("%d", &v->size);

    for (int i = 0; i < v->size; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", &v->arr[i]);
    }
}

void modify_element(struct vector *v, int index, int new_value)
{
    index >= 0 && index < v->size ? v->arr[index] = new_value : printf("Invalid index.\n");
}

void multiply_by_scalar(struct vector *v, int scalar)
{
    for (int i = 0; i < v->size; i++)
        v->arr[i] = v->arr[i] * scalar;
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
    int index, value, scalar;

    create_vector(&v);

    printf("Enter index to modify ( index start from 0 ): ");
    scanf("%d", &index);

    printf("Enter new value: ");
    scanf("%d", &value);
    modify_element(&v, index, value);

    printf("Enter scalar value: ");
    scanf("%d", &scalar);
    multiply_by_scalar(&v, scalar);

    printf("Final vector:\n");
    display_vector(v);

    return 0;
}