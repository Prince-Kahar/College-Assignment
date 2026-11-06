#include<stdio.h>
int main() {
    int num , i , r[1000] ;
    printf("Enter a Value : ");
    scanf("%d",&num);
    if(num == 0)
        printf("Binary is 0 ");
    for( i = 0 ; num > 0 ; i++ ) {
        r[i] = num % 2 ;
        num /= 2;
    }
    printf("Binary Is : ");
    for( int j = i-1 ; j >= 0 ; j-- ) {
        printf("%d",r[j]);
    }
    return 0;
}