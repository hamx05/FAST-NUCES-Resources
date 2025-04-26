#include <stdio.h>

int main() {
    int num1, num2, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // FOR LCM

    max = (num1 > num2) ? num1 : num2;

    while (1) {
        if (max % num1 == 0 && max % num2 == 0) {
            printf("LCM of %d and %d is %d\n", num1, num2, max);
            break;
        }
        max++;
    }
    
    // FOR GCD:
    
     while (num1 != num2) {
        if (num1 > num2) {
            num1 = num1 - num2;
        }
        else {
            num2 = num2 - num1;
        }
            
    }

    printf("GCD of the two numbers is %d\n", num1);


    return 0;
}
