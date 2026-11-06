// Q4: Print the first N even numbers
#include<stdio.h>
int main() {
    int n , i ; 
    printf("Enter a Number : ");
    scanf("%d", &n );
    printf("First %d Even Numbers Are : " , n );
    for( i = 0 ; i < n ; i++ ) {
        printf("%d  " , i * 2 );
    }
    return 0;
}