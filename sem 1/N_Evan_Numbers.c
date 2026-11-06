// Print the first N even numbers 
#include<stdio.h>
int main() {
    int num ; 
    printf("Entetr a Number : ");
    scanf("%d" , &num );
    printf("%d Even Numbers " , num );
    for  ( int i = 0 ; i < num ; i++ ) {
        printf("%d  " , i * 2 );
    }
    return 0;
}