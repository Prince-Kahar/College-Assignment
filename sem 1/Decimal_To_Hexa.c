#include<stdio.h>
int main() {
    int num , i , r ;
    char a[100]; 
    printf("Enter a value : ");
    scanf("%d", &num);
    if( num == 0 ) {
        printf("Hexa Decimal : 0");
        return 0; 
    }
    for( i = 0 ; num > 0 ; i++ ) {
        r = num % 16 ;
        if( r < 10 ) 
            a[i] = r + 48 ;
        else
            a[i] = r + 55 ;
        num /= 16 ;
    }
    printf("Hexa Decimal : ");
    for( int j = i - 1 ; j >= 0 ; j-- ) {
        printf("%c", a[j]);
    }
    return 0; 
}