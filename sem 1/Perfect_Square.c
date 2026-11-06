// Check whether a number is a perfect square 
#include<stdio.h>
int main() {
    int num ; 
    printf("Enter a Number : ");
    scanf("%d" , &num );
    for( int i = 0 ; i < num ; i++) {
        if ( ( i * i ) == num )
            printf("%d is Pefect Square Number " , num );
        else {
            printf("%d is not Perfect Square Number " , num );
            return 0;
        }
    }
}