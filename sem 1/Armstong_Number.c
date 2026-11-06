#include<stdio.h>
int main() {
    int a , sum = 0 ;
    int n = 153;
    printf("Number is %d",n);
    for(; n!=0 ; n/=10) {
        a = n % 10;
        sum += ( a*a*a );
    }
    printf("\nAnswer is %d\n" , sum );
    if(sum == n)
        printf("%d is Armstrong Number" , n );
    else
        printf("%d is not Armstrong number" , n );
    return 0;
}