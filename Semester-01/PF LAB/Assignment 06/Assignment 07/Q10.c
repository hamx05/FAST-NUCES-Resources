#include <stdio.h>

int main() {
    int i, j, N, S, arr[N], right=0, left=0, sum=0;  
    printf("Enter the size of the array: ");
    scanf("%d", &N);

   
    printf("Enter the elements of the array: ");
    for (i=0; i<N; i++) {
        scanf("%d", &arr[i]);  
    }

    printf("Enter the target sum (S): ");
    scanf("%d", &S);

     

    while (right < N) { 
        sum += arr[right];  

        while (sum > S) {  
            sum -= arr[left];  
            left++;  
        }

        if (sum == S) {  
            printf("Subarray found between indices %d and %d\n", left, right);
            printf("Subarray elements: ");
            for (i = left; i <= right; i++) {
                printf("%d ", arr[i]);  
            }
            return 0;  
        }

        right++; 
    }

    printf("No subarray found with sum equal to %d\n", S);  
    return 0;
}

