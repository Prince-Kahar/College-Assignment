// Q10:	Convert a string to lowercase
#include<stdio.h>
int main() {
    char str[1000] ;
    printf("Enter a Strting : ");
    fgets( str , sizeof(str) , stdin );
    for ( int i = 0 ; str[i] != '\0'; i++ ) {
        if( str[i] >= 'A' && str[i] <= 'Z' ) {
            str[i] += 32 ; 
        }
    }
    printf("Lower String : %s " , str);
    return 0;
}