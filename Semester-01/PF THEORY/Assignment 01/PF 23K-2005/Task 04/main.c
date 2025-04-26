#include <stdio.h>

void main() {

    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    
    int array[64];
    int count=0;
    int r;
    while (num>0) {
        r = num % 2; //
        num = num / 2;
        array[count] = r;
        count++;
    }
    
    for(int i = count-1; i >= 0; i--){
        printf("%d", array[i]);
    }
}