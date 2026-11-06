// Q11:  Search for an element in an array
#include<stdio.h>
int main() {
    int size , i , find , a ;
    printf("Enter Array Size : ");
    scanf("%d" , &size );
    int arr[size] ;
    for ( i = 0 ; i < size ; i++ ) {
        printf("Enter arr[%d] : " , i );
        scanf("%d" , &arr[i] );
    }
    printf("Which Element You Have To Find : ") ; 
    scanf("%d" , &find );
    for ( i = 0 ; i < size ; i++ ) {
        if( find == arr[i] ) {
            printf("%d is Available on Index of %d \n" , find , i );
            a++ ; 
        }
    }
    if( !a ) {
        printf("%d is not Found " , find );
    }
    return 0;
}