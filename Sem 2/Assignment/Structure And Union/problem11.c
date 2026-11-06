/*
Create two structure named metric and British which store values of distances. 
The metric strucure stores the values in metres and centimetres and the British structure stores the values in feet and inches. 
Write a program that reads values for the structure variables and adds values contained in one variable of metric to the contents of another variable of British. 
The program should display the result in the formal of feet and inches or metres and centimeters as required.
    
    1 metre = 100 centimetres
    1 foot = 12 inches
    1 inch = 2.54 centimetres
    1 foot = 30.48 centimetres
*/

#include <stdio.h>

struct metric
{
    int metre;
    int centimetre;
} m;

struct British
{
    int feet;
    int inch;
} b;

void add_into_metric(struct metric m, struct British b)
{
    float total_cm;

    total_cm = (m.metre * 100) + m.centimetre;
    total_cm += (b.feet * 30.48) + (b.inch * 2.54);

    m.metre = total_cm / 100;
    m.centimetre = (int)total_cm % 100;

    printf("Result in Metric System:\n");
    printf("%d metres %d centimetres\n", m.metre, m.centimetre);
}

void add_into_british(struct metric m, struct British b)
{
    float total_inches;

    total_inches = (m.metre * 100 + m.centimetre) / 2.54;
    total_inches += (b.feet * 12) + b.inch;

    b.feet = total_inches / 12;
    b.inch = (int)total_inches % 12;

    printf("Result in British System:\n");
    printf("%d feet %d inches\n", b.feet, b.inch);
}

int main()
{
    int choice;

    printf("Enter metric distance (metres & centimetres): ");
    scanf("%d %d", &m.metre, &m.centimetre);

    printf("Enter british distance (feet & inches): ");
    scanf("%d %d", &b.feet, &b.inch);

    printf("Display result in:\n");
    printf("1. Metric system\n");
    printf("2. British system\n");
    scanf("%d", &choice);

    if (choice == 1)
        add_into_metric(m, b);
    else
        add_into_british(m, b);
    return 0;
}