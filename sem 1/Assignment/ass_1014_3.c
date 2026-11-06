// Q3: Find the largest of four numbers
#include<stdio.h>
int main() {
    int arr[4] , i ;

    //Dynamic Array
    for( i = 0 ; i < 4 ; i++ ) {
        printf("Enter a arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
  
    int large = arr[0] ; // Assumed First Element is Largest
    for( i = 1 ; i < 4 ; i++ ) {
        if(large < arr[i] ) {
            large = arr[i] ;
        }
    }
    
    printf("Large is : %d " , large );
    return 0;
}