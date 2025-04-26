#include <stdio.h>
#include <stdlib.h>
int main(){
	char read[50];
    FILE *file1 = fopen("file1.txt", "w");
if (file1 == NULL){
	 printf("file1 creation failed.");
  exit(1);
   }
    fprintf(file1, "Hello world from file 1.\n");
    
   fclose(file1);

    FILE *file2 = fopen("file2.txt", "w");
 if (file2 == NULL){
        printf("file2 creation failed.");
        exit(1);
    }
    fprintf(file2, "Hello world from file 2.\n");
    fclose(file2);

    FILE *input1 = fopen("file1.txt", "r");
    FILE *input2 = fopen("file2.txt", "r");
    FILE *mergedFile = fopen("mergedFile.txt", "w");

if (input1 == NULL || input2 == NULL || mergedFile == NULL){
        printf("Error opening files");
        exit(1);
    }
char ch;
while ((ch = fgetc(input1)) != EOF){
        fputc(ch, mergedFile);
        printf("%c",ch);
    }
while ((ch = fgetc(input2)) != EOF){
        fputc(ch, mergedFile);
         printf("%c",ch);
    }
    fclose(input1);
    fclose(input2);
    fclose(mergedFile);

    printf("Files have been merged successfully!\n");

return 0;
}

