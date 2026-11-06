// Convert meters to centimeters 
//meter = cm 100
#include<stdio.h>
#define meters_to_centimeters  100 
int main () {
    float cm , meter ;
    printf("Enter Meter : ");
    scanf("%f" , &meter );
    printf("centimeters  = %f" , meter * meters_to_centimeters ) ;
    return 0;
}