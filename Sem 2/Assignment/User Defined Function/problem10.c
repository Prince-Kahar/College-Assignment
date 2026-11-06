/*
Develop a modular interactive program using functions that reads the values of three sides of a triangle and displays either its area or its perimeter as per the request of the user. Given the three sides a, b and c.
        Perimeter = a + b + c
            Area = sqrt ((s-a)*(s-b)*(s-c))
    Where       s = (a+b+c)/2
*/

#include <stdio.h>
#include <math.h>

void read_sides(float *a, float *b, float *c)
{
    printf("Enter first side: ");
    scanf("%f", a);
    printf("Enter second side: ");
    scanf("%f", b);
    printf("Enter third side: ");
    scanf("%f", c);
}

int valid_triangle(float a, float b, float c)
{
    if ((a + b > c) && (a + c > b) && (b + c > a))
        return 1;
    return 0;
}

float perimeter(float a, float b, float c)
{
    return a + b + c;
}

float area(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    float a, b, c;
    char operation;

    read_sides(&a, &b, &c);
    if(!valid_triangle(a,b,c))
    {
        printf("Error! The given sides do not form a valid triangle.\n");
        return 1;
    }
    printf("Enter one of the followings: ");
    printf("\n\tA. Perimeter of the triangle ");
    printf("\n\tB. Area of the triangle ");
    printf("\n");

    scanf(" %c", &operation);
    if(operation == 'A' || operation == 'a')
        printf("Result -> %.2f\n", perimeter(a, b, c));
    else if(operation == 'B' || operation == 'b')
        printf("Result -> %.2f\n", area(a, b, c));
    else
        printf("Invalid operation\n");
    return 0;
}