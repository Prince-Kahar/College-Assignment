/*
Define a structure named census with the following three members:
    A. A character array city[] to store names
    B. A long integer to store population of the city
    C. A float member to store the literacy level

Write a program to do the following:
    A. To read details for 5 cities randomly using an array variable
    B. To sort the list alphabetically
    C. To sort the list based on literacy level
    D. To sort the list based on population
    E. To display sorted lists.
*/

#include <stdio.h>
#include <string.h>

struct census
{
    char city[30];
    long int population;
    float literacy;
} city[5];

void input_data(struct census c[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter details of city %d\n", i + 1);
        printf("City name: ");
        scanf("%s", c[i].city);
        printf("Population ( in Lakhs ): ");
        scanf("%ld", &c[i].population);
        printf("Literacy level ( in Percentage ): ");
        scanf("%f", &c[i].literacy);
    }
}

void sort_by_name(struct census c[])
{
    struct census temp;
    for (int i = 0; i < 5 - 1; i++)
        for (int j = i + 1; j < 5; j++)
            if (strcmp(c[i].city, c[j].city) > 0)
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
}

void sort_by_literacy(struct census c[])
{
    struct census temp;
    for (int i = 0; i < 5 - 1; i++)
        for (int j = i + 1; j < 5; j++)
            if (c[i].literacy > c[j].literacy)
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
}

void sort_by_population(struct census c[])
{
    struct census temp;
    for (int i = 0; i < 5 - 1; i++)
        for (int j = i + 1; j < 5; j++)
            if (c[i].population > c[j].population)
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
}

void display(struct census c[])
{
    printf("\n%-15s %-15s %-15s\n", "City", "Population", "Literacy");
    for (int i = 0; i < 5; i++)
        printf("%-15s %-15ld %-15.2f\n", c[i].city, c[i].population, c[i].literacy);
}

int main()
{
    input_data(city);

    sort_by_name(city);
    printf("\nSorted Alphabetically (City Name):");
    display(city);

    sort_by_literacy(city);
    printf("\nSorted by Literacy Level:");
    display(city);

    sort_by_population(city);
    printf("\nSorted by Population:");
    display(city);

    return 0;
}