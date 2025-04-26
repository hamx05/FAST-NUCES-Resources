#include <stdio.h>

void findSeries(int a, int b, int n) {
    if (n > 0) {
        printf("%d, ", a);
        findSeries(b, a+b, n-1);
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &n);
	printf("Fibonacci series of %d numbers: ", n);
    findSeries(0,1,n);
    
	return 0;
}

