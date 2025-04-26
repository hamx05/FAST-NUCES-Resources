#include <stdio.h>

void Fibonacci (int prNo, int crNo, int index, int range) {
	int nextNo;
	
	if (range <= index) {
		return;
	}
	
	nextNo = prNo + crNo;
	prNo = crNo;
	crNo = nextNo;
	
	printf("%d, ", nextNo);
	index++;
	Fibonacci (prNo, crNo, index, range);
	
	return;
}

int main () {
	
	int range;
	int prNo = 0, crNo = 1;
	int index=1;
	
	printf("enter the range: ");
	scanf("%d", &range);
	
	printf("%d, %d, ", prNo, crNo);
	Fibonacci (prNo, crNo, index, range);
	
	return 0;
}

