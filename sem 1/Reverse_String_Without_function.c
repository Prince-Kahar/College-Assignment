// Reverse a string without using inbuilt function
#include<stdio.h>
int main() {
    int i , len = 0;
    char name[100];
    printf("Enter Your Name : ");
    fgets(name , sizeof(name) , stdin );
    
    for(i=0 ; name[i]!='\0' ; i++ ) {
        len++;
    }
    len--;
    printf("Reverse : ");
    for(i=len ; i>=0 ; i--) {
        printf("%c",name[i]);
    }
    return 0;
}