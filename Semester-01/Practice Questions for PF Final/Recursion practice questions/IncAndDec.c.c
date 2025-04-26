#include <stdio.h>

void increasing (int x, int n) {
	// base case: 
	if (x>n) { return; }
	printf("%d\n", x);
	increasing (x+1, n);
	return;	
}

void decreasing (int x, int n) {
	// base case: 
	if (x>n) { return; }
	decreasing (x+1, n);
	printf("%d\n", x);
	return;
}

int main () {
	
	int a, b;
	int c, d;
	
	printf("enter the lower & upper limit for increasing series: ");
	scanf("%d %d", &a, &b);
	increasing(a,b);
	
	printf("enter the lower & upper limit for decreasing series: ");
	scanf("%d %d", &c, &d);
	decreasing(c,d);
	
	return 0;
}

