// Check whether a number is strong 
#include<stdio.h>
int main() {
    int num , digit , i , fact , j , sum = 0 ;
    printf("Enter a Number : ");
    scanf("%d" , &num );
    for ( i = num ; i > 0 ; i /= 10 ) {
        digit = i % 10 ;
        fact = 1 ;
        for ( j = 1 ; j <= digit ; j++ ) {
            fact *= j ;
        } 
        sum += fact ;
    }
    printf("%d\n" , sum );
    if ( sum == num )
        printf("%d is a Strong Number " , num );
    else
        printf("%d is not a Strong Number" , num );
    return 0;
}