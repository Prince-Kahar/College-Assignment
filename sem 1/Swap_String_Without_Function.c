#include<stdio.h>~
int main() {
    char str1[100] = "BCA" , str2[100] = "M.SC.IT" , str3[100] ;
    int i ;
    printf("\nString 1 : %s ",str1);
    printf("\nString 2 : %s ",str2);

    for( i = 0 ; str1[i] != '\0' ; i++ ) {
        str3[i] = str1[i];
    }
    str3[i] = '\0';

    for( i = 0 ; str2[i] != '\0' ; i++ ) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';

    for( i = 0 ; str3[i] != '\0' ; i++ ) {
        str2[i] = str3[i];
    }
    str2[i] = '\0';


    printf("\n\nAfter Swaping : ");
    printf("\nString 1 : %s ",str1);
    printf("\nString 2 : %s ",str2);
    return 0;
}