#include <stdio.h>

int main() {
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Use fseek to move to the appropriate position (assuming integers are separated by spaces)
    fseek(file, 1, SEEK_CUR);

    // Calculate the sum of the first five integers
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        int number;
        if (fscanf(file, "%d", &number) == 1) {
            sum += number;
        } else {
            // Handle the case where there are not enough integers in the file
            fprintf(stderr, "Error reading integer from file");
            fclose(file);
            return 1;
        }
    }

    // Print the result
    printf("Sum of the first five integers: %d\n", sum);

    fclose(file);
    return 0;
}

