// Q14:	Count the number of words in a string
#include<stdio.h>
int main() {
    char str[1000] ;
    int i , count = 0 ;
    printf("Enter a String : ");
    fgets( str , sizeof(str) , stdin );
    for ( i = 0 ; str[i] != '\0'  ; i++ ) {
        if ( ( str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ) && ( i > 0 && str[i-1] != ' ' && str[i-1] != '\t' && str[i] != '\n' ) ) {
            count++ ; 
        }
    }

    
    if( i > 0 && str[i-1] != ' ' && str[i-1] != '\t' && str[i] != '\n' ) {
        count++;
    }
    printf("Number of words : %d " , count);
    return 0;
}