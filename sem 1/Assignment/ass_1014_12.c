// Q12: Check whether a number is prime
#include<stdio.h>
int main() {
    int n , prime = 0 ;
    printf("Enter a value : ");
    scanf("%d" , &n );
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( n % i == 0 ) {
            prime++ ;
        }
    }
    if ( prime == 2 ) {
        printf("%d is Prime Number " , n);
    }
    else {
        printf("%d is Non - Prime Number " , n);
    }
    return 0;
}