#include <stdio.h> 

int sum (int x, int n) {
	int ans=0;
	if (x>n) return 0;
	return ans + x + sum(x+1,n);
}

int main () {
	int n;
	printf("Enter n for sum: ");
	scanf("%d", &n);
	
	int result = sum (1,n);
	printf("Result: %d", result);
	return 0;
}
