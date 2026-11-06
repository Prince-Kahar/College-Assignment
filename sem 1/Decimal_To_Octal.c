#include<stdio.h>
int main() { 
    int num , i , r[1000] ;
    printf("Enter a Value : ");
    scanf("%d",&num);
    if(num == 0)
        printf("Octal : 0 ");
    for( i = 0 ; num > 0 ; i++ ) {
        r[i] = num % 8 ;
        num /= 8 ;
    }
    printf("Octal : ");
    for( int j = i-1 ; j >= 0 ; j-- ) {
        printf("%d",r[j]);
    }
    return 0;
}