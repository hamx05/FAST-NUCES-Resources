#include <stdio.h>
#include <string.h>

void reverseString(char test[]) {
    int length = strlen(test);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end using a temporary variable
        char temp = test[start];
        test[start] = test[end];
        test[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
}

int main() {
    char test[] = "this is a test string for my program";
    reverseString(test);
    printf("Reversed String: %s\n", test);

    return 0;
}

