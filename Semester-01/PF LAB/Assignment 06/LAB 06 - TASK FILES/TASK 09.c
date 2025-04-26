#include <stdio.h>

int main() {
    
    int arr[]={4,1,6,8,10,21,8,9,2,6},min=22,max=0,i=0;
    
    for(i=0;i<8;i++)
    {
        if(arr[i]<min)
        min=arr[i];
        if(arr[i]>max)
        max=arr[i];
    }
    printf("The minimum number is %d", min);
	printf("\nThe maximum number is %d", max);
    return 0;
}
