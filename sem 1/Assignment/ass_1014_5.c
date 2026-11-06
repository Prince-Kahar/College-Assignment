// Q5: Subtract two matrices 
#include<stdio.h>
int main() {
    int r , c ;
    int matrix1[100][100] , matrix2[100][100] , sub[100][100] ; 
    int i , j ; 
    printf("Enter Row : ") ;
    scanf("%d",&r);
    printf("Enter Column : ");
    scanf("%d",&c);
  
    printf("\n");
    printf("Value of matrix 1 : \n");
  
    for( i = 0 ; i < r ; i++ ) {
        for( j = 0 ; j < c ; j++ ) {
            printf("matrix1[%d][%d] : " , i , j );
            scanf("%d" , &matrix1[i][j]);
        }
    }
  
    printf("\n");
    printf("Value of matrix 2 : \n");
  
    for( i = 0 ; i < r ; i++ ) {
        for( j = 0 ; j < c ; j++ ) {
            printf("matrix2[%d][%d] : " , i , j );
            scanf("%d" , &matrix2[i][j]);
        }
    } 
  
    for( i = 0 ; i < r ; i++ ) {
        for( j = 0 ; j < c ; j++ ) {
            sub[i][j] = matrix1[i][j] - matrix2[i][j] ;
        }
    }
  
    printf("\n");
    printf("matrix 1 : \n");
  
    for( i = 0 ; i < r ; i++ ) {
        for( j = 0 ; j < c ; j++ ) {
            printf("%d\t",matrix1[i][j]);
        }
        printf("\n");
    }
  
    printf("\n");
    printf("matrix 2 : \n");
  
    for( i = 0 ; i < r ; i++ ) {
        for( j = 0 ; j < c ; j++ ) {
            printf("%d\t",matrix2[i][j]);
        }
        printf("\n");
    }
  
    printf("\n");
    printf("Substraction : \n");
  
    for( i = 0 ; i < r ; i++ ) {
        for( j = 0 ; j < c ; j++ ) {
            printf("%d\t",sub[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}