#include <stdio.h>

int findGCDWithLoop(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCDWithRecursion(int a, int b) {
	if (b==0) {
		return a;
	}
	
	else {
		return findGCDWithRecursion(b, a%b);
	}
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
	printf("GCD using loops: %d\n", findGCDWithLoop(num1, num2));
	printf("GCD using recursion: %d\n", findGCDWithRecursion(num1, num2));

    return 0;
}

