// Q7: Count vowels in a string 
#include<stdio.h>
int main() {
    char str[1000] ;
    int vowel = 0 ; 
    printf("Enter Your String : ");
    fgets( str , sizeof ( str ) , stdin );

    for ( int i = 0 ; str[i] != '\0' ; i++ ) {
        if( str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ) {
            vowel++ ; // if condition is true then vowel increase by 1
        }
    }
    printf("There are %d Vowels in %s " , vowel , str );
    return 0;
}