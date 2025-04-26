#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 100

// Function to add a new category to categories.txt
void addCategory() {
    char categoryName[MAX_NAME_LENGTH];
    int categoryId;

    printf("Enter the category name: ");
    scanf("%s", categoryName);
    
    printf("Enter the category ID: ");
    scanf("%d", &categoryId);

    FILE *categoriesFile = fopen("categories.txt", "a");
    fprintf(categoriesFile, "%s %d\n", categoryName, categoryId);
    fclose(categoriesFile);

    printf("Category added successfully!\n");
}

// Function to add a new product to products.txt
void addProduct() {
    char productName[MAX_NAME_LENGTH];
    float productPrice;
    int categoryId;

    printf("Enter the product name: ");
    scanf("%s", productName);

    printf("Enter the product price: ");
    scanf("%f", &productPrice);

    printf("Enter the category ID: ");
    scanf("%d", &categoryId);

    FILE *productsFile = fopen("products.txt", "a");
    fprintf(productsFile, "%s %.2f %d\n", productName, productPrice, categoryId);
    fclose(productsFile);

    printf("Product added successfully!\n");
}

// Function to generate final.txt by organizing products by category
void generateFinalResult() {
    FILE *productsFile = fopen("products.txt", "r");
    FILE *categoriesFile = fopen("categories.txt", "r");
    FILE *finalFile = fopen("final.txt", "w");

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, categoriesFile) != NULL) {
        int categoryId;
        char categoryName[MAX_NAME_LENGTH];

        sscanf(line, "%s %d", categoryName, &categoryId);
        fprintf(finalFile, "%s ", categoryName);

        rewind(productsFile);

        while (fgets(line, MAX_LINE_LENGTH, productsFile) != NULL) {
            int productCategoryId;
            char productName[MAX_NAME_LENGTH];
            float productPrice;

            sscanf(line, "%s %f %d", productName, &productPrice, &productCategoryId);

            if (productCategoryId == categoryId) {
                fprintf(finalFile, "%s %.2f ", productName, productPrice);
            }
        }

        fprintf(finalFile, "\n");
    }

    fclose(productsFile);
    fclose(categoriesFile);
    fclose(finalFile);

    printf("Final result generated successfully!\n");
}

int main() {
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add category\n");
        printf("2. Add product\n");
        printf("3. Generate final result\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCategory();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                generateFinalResult();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

