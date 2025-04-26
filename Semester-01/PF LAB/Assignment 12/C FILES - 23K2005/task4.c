#include <stdio.h>

int main() {
    FILE *file = fopen("budget.txt", "w");

    if (file == NULL) {
        printf("File creation failed due to error.");
        return 1;
    }    

    fprintf(file, "-462.13 486.47 973.79\n");
    fprintf(file, "755.42 843.04 -963.67\n");
    fprintf(file, "442.58 -843.02 -462.86\n");
    fprintf(file, "-233.93 -821.67 399.59\n");
    fprintf(file, "-379.65 -556.37 837.46\n");
    fprintf(file, "55.18 -144.93 -93.15\n");
    fprintf(file, "533.73 804.64 -66.25\n");
    fprintf(file, "-922.12 914.68 -264.67\n");
    fprintf(file, "-600.27 -838.59 747.02\n");
    fprintf(file, "-962.97 49.96 -677.79\n");

    fclose(file);
    file = fopen("budget.txt", "r");

    if (file == NULL) {
        printf("Error opening file");
        return 1; 
    
}
    double sum1=0, sum2=0, sum3=0;
	double num1, num2, num3;
    
    while (fscanf(file, "%lf %lf %lf", &num1, &num2, &num3) == 3) {
        sum1 += num1;
        sum2 += num2;
        sum3 += num3;
    }
    printf("The file has been created.\n");
    printf("Column sums are: \n%.2lf \n%.2lf \n%.2lf\n", sum1, sum2, sum3);

    fclose(file);

    return 0;
}

