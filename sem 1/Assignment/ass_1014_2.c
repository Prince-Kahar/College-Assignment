//Q2: Reverse a given string
#include<stdio.h>
int main() {
    char str[100] ;
    int len = 0 ;
    printf("Enter a String : ");
    fgets( str , sizeof(str) , stdin );

    // Count Length of the String
    for( int i = 0 ; str[i] != '\0' ; i++ ) {
        len++ ;
    }
    len-- ; // Know Orijinal langth without '\0'
  
    // Print Reverse string Character by Character
    for( int j = len ; str[j] >= 0 ; j-- ) {
        printf("%c",str[j]);
    }
    return 0;
}