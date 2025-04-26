#include <stdio.h>

int main() {
    FILE * textfile;
    int score;
    int s[10];
    int n = 0;
    int i;
    textfile = fopen("source.txt", "r");
    if (textfile == NULL) {
        printf("Can't open scores.txt\n");
        exit(1);
    }
    for (;;) {
        fscanf(textfile, "%d", & score);
        if (score == -1) break;
        s[n] = score;
        n++;
    }
    close(textfile);

    s[n] = 99;
    n++;

    textfile = fopen("source.txt", "w");
    for (i = 0; i < n; i++) {
        fprintf(textfile, "%i ", s[i]);
    }
    fprintf(textfile, "-1\n");
}
