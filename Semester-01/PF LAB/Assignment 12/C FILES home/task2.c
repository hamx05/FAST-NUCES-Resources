#include <stdio.h>
int main(){
   FILE *inputFile = fopen("input.txt", "r");
    
	if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        exit(1);
}
    FILE *outputFile = fopen("output.txt", "w");
    
    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        fclose(inputFile);
        exit (1);
    }
int occurrences[26] = {0};
int totalCharacters = 0;
int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
    	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
            totalCharacters++;
    	if (ch >= 'a' && ch <= 'z') {
        	ch = ch - 'a' + 'A';
    	}
        occurrences[ch - 'A']++;
    	}
    }
	   
    for (int i = 0; i < 26; i++){
    	fprintf(outputFile, "%c (Occurrences of %c/%c) = %d\n", 'A' + i, 'A' + i, 'a' + i, occurrences[i]);
    	printf("%c (Occurrences of %c/%c) = %d\n", 'A' + i, 'A' + i, 'a' + i, occurrences[i] );
	}

    fprintf(outputFile, "Total characters read = %d\n", totalCharacters);
    printf("Total characters read = %d\n", totalCharacters);

    fclose(inputFile);
    fclose(outputFile);

    printf("Character occurrences written to output.txt.\n");

    return 0;
}

