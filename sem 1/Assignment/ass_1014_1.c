// Q1: Find the second largest element in an array
#include<stdio.h>
int main() {
    int n , i , j ;
    printf("Enter Your Array Size : ") ;
    scanf("%d" , &n ) ;
    int arr[n] ;
  
    // Dynamic array
    for( i = 0 ; i < n ; i++ ) {
        printf("Enter Value of a[%d] :- " , i ) ;
        scanf("%d" , &arr[i] ) ;
    }
  
    // Bubble Short
    for( i = 0 ; i < n-1 ; i++ )  {
        for( j = 0 ; j < n-i-1 ; j++ ) {
            if(arr[j]<arr[j+1]) {
                arr[j] = arr[j]*arr[j+1];
                arr[j+1] = arr[j]/arr[j+1];
                arr[j] = arr[j]/arr[j+1];
            }
        }
    }
    // Print Second Largest Element 
    printf("\nSecond Largest Element is %d " , arr[1]);
    return 0;
}
