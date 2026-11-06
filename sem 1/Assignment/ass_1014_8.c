// Q8: Calculate the circumference of a circle
#include<stdio.h>
#define pi 3.14 // Constant Declare
int main() {
    float r ; 
    printf("Enter Radius : ");
    scanf("%f" , &r );
    printf("Circumference of a Circle is %f " , 2*pi*r); // Calculate and Print Circumference of a Circle
    return 0;
}