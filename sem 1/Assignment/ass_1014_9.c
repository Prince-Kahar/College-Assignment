// Q9: Delete an element from an array

#include<stdio.h>
int main() {
    int size , pos , i ; 
    printf("Enter Array size : ");
    scanf("%d" , &size);
    int arr[size] ;
    for( i = 0 ; i < size ; i++ ) {
        printf("Enter arr[%d] : " , i );
        scanf("%d" , &arr[i] );
    }
    printf("Which Index Number You Have To Delete ( 0 - %d ) : " , size-1 );
    scanf("%d" , &pos );
    for( i = pos ; i < size ; i++ ) {
        arr[i] = arr[i+1] ; // Shift Element Left
    }
    size-- ; // Reduce Array Size
    // Print New Array
    printf("Array after Deletion : ");
    for ( i = 0 ; i < size ; i++ ) {
        printf("%d  " , arr[i] );
    }
    return 0;
}