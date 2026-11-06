#include<stdio.h>
int main() {
    int n , i , prime=0;
    printf("Enter a Value : ");
    scanf("%d",&n);
    for( i=2 ; i <= n ; i++) {
        if(n % i == 0) {
            prime++;
        }
    }
    if(prime==1) {
        printf("%d is prime Number ",n);
    }
    else if (n==1) {
        printf("%d is not a prime nuber or non - prime number ",n);
    }
    else {
        printf("%d is non - prime Number ",n);
    }
    return 0;
}