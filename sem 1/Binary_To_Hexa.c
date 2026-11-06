#include<stdio.h>
int main() {
    int n , decimal = 0 , base = 1 , j , r ;
    char hex[1000] ; 
    printf("Enter a Binary Value : ");
    scanf("%d", &n );
    for ( int i = 0 ; n > 0 ; i++ ) {
        int r = n % 10 ;
        decimal += r * base ;
        base *= 2 ;
        n /= 10 ; 
    }

    printf("Decimal : %d ",decimal );

    for ( j = 0 ; decimal > 0 ; j++ ) {
        r = decimal % 16 ;
        if ( r < 10 ) {
            hex [j] = 48 + r ;
        }
        else {
            hex [j] = 55 + r ;
        }
        decimal /= 16 ;
    }

    printf("\nHexa Decimal :- ") ;
    for( int k = j - 1 ; k >= 0 ; k-- ) {
        printf(" %c" , hex[k]);
    }
    return 0;
}