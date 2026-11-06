// Convert miles to kilometers 
// miles = km 1.60934
#include<stdio.h>
#define miles_to_km 1.60934 
int main () {
    float km , mil ;
    printf("Enter Miles : ");
    scanf("%f" , &mil );
    printf("KiloMeter = %f" , mil * miles_to_km ) ;
    return 0;
}