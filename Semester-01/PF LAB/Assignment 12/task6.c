#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define VOWELS "aeiou"

void encrypt_file(char *input_file, char *output_file) {
  FILE *in_file, *out_file;
  char ch;
  int vowel_count = 0;

  // Check and modify input file path
  // Add full path if not already provided
  if (!strchr(input_file, '\\')) {
    char full_path[256];
    sprintf(full_path, "C:\\Users\\3TEE\\Desktop\\%s", input_file);
    input_file = full_path;
  }

  // Open the input file
  in_file = fopen(input_file, "r");
  if (!in_file) {
    printf("Error opening input file: %s\n", input_file);
    exit(1);
  }

  // Check and modify output file path
  // Add full path if not already provided
  if (!strchr(output_file, '\\')) {
    char full_path[256];
    sprintf(full_path, "C:\\Users\\3TEE\\Desktop\\%s", output_file);
    output_file = full_path;
  }

  // Open the output file
  out_file = fopen(output_file, "w");
  if (!out_file) {
    printf("Error opening output file: %s\n", output_file);
    exit(1);
  }

  // Continue with the existing encryption logic
  // ...

  // ...

  fclose(in_file);
  fclose(out_file);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    exit(1);
  }

  encrypt_file(argv[1], argv[2]);

  printf("File encrypted successfully!\n");

  return 0;
}

