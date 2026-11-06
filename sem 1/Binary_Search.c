#include<stdio.h>
int main() {
    int num[100] ,size , search , low=0 , mid , s=0;
    printf("Enter Array Size :- ");
    scanf("%d",&size);

    for(int i=0; i<size; i++) {
        printf("Enter num[%d] --> ",i);
        scanf("%d",&num[i]);
    }

    printf("Enter number To Be Searched --> ");
    scanf("%d",&search);

    while(low<=size) {
        mid = (low+size)/2;
        if(num[mid]<search) {
            low = mid+1;
        }
        else if(num[mid]==size) {
            printf("%d Is Found",search);
            s++;
        }
        
        else if(num[mid]>search) {
            size = mid-1; 
        }
        else {
            printf("%d Is Not Found");
        }
    }
    return 0;
}