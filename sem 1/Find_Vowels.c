#include<stdio.h>
int main() {
    int i,vowels = 0;
    char name[100];
    printf("Enter Your Name : ");
    fgets( name , sizeof(name) , stdin );
    for(i=0 ; name[i]!='\0' ; i++ ) {
        if(name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U' || name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' ) {
            vowels++;
        }
    }
    printf("Vowels = %d" , vowels);
    return 0;
}