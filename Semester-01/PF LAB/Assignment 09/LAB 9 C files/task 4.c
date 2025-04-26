#include <stdio.h> 

int findProduct(int num1, int num2,int product) {
	
	if(num2!=0) {
		product+=num1;
		return findProduct(num1, num2-1,product);
	}
	
	return product;
}

int main () {
	int num1,num2, result;
	
	printf("enter the two numbers: ");
	scanf("%d%d", &num1, &num2);
	result = findProduct(num1,num2,0);
	printf("%d", result);
	
	return 0;
}
