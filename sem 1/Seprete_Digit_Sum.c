#include<stdio.h>
int main() {
    int num , a , sum=0;
    printf("Enter a Value :- ");
    scanf("%d",&num);
    printf("number is %d",num);
    for(; num>0 || num<0; num/=10) {
        a = num%10;
        sum+=a;
    }
    printf("\n%d",sum);
    return 0;
}