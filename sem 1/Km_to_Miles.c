// Convert kilometers to miles 
// km = miles 0.621371
#include<stdio.h>
#define km_to_miles 0.621371 
int main () {
    float km , mil ;
    printf("Enter Kilometer : ");
    scanf("%f" , &km );
    printf("Miles = %f" , km * km_to_miles ) ;
    return 0;
}