#include<stdio.h>
int main() {

    int num[100] , size , search , cat = 0;
    printf("Enter Array Size :- ");
    scanf("%d",&size);

    for(int i=0; i<size; i++) {
        printf("Enter num[%d] --> ",i);
        scanf("%d",&num[i]);
    }

    printf("Enter number To Be Searched --> ");
    scanf("%d",&search);
    for(int i=0; i<size; i++) {
        if(search == num[i]) {
            printf("%d is Available on index %d\n",search,i);
            cat=1;
        }        
    }
    if(!cat)
        printf("Number is not Available ");
    return 0;
}