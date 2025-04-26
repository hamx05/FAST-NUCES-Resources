#include <stdio.h>

int CalculateSum(int *ptr, int n) {
    int i,sum=0;

    for (i=0 ;i<n ;i++) {
        sum += *(ptr+i);
    }
    return sum;
}

int main() {
    int n, result;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *ptr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    result = CalculateSum(ptr,n);  
    printf("Sum of the array is: %d\n", result);

    free(ptr);

    return 0;
}

