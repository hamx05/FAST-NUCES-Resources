#include <stdio.h>
#include <string.h>

void SaveInOrder(char *txt[], int maxSentences) {
    char organizedSentences[6][50];
    int i, j = 0;

    // Save sentences containing "one"
    for (i = 0; i < maxSentences; i++) {
        if (strstr(txt[i], "one") != NULL) {
            strcpy(organizedSentences[j], txt[i]);
            j++;
        }
    }

    // Save sentences containing "two"
    for (i = 0; i < maxSentences; i++) {
        if (strstr(txt[i], "two") != NULL) {
            strcpy(organizedSentences[j], txt[i]);
            j++;
        }
    }

    // Save sentences containing "three"
    for (i = 0; i < maxSentences; i++) {
        if (strstr(txt[i], "three") != NULL) {
            strcpy(organizedSentences[j], txt[i]);
            j++;
        }
    }

    // Save sentences containing neither "one", "two", nor "three"
    for (i = 0; i < maxSentences; i++) {
        if (strstr(txt[i], "one") == NULL && strstr(txt[i], "two") == NULL && strstr(txt[i], "three") == NULL) {
            strcpy(organizedSentences[j], txt[i]);
            j++;
        }
    }

    printf("Organized:\n");
    for (int i = 0; i < maxSentences; i++) {
        printf("%s\n", organizedSentences[i]);
    }
}

int main() {
    char *txt[] = {"this sentence contains two", "one is so easy", "what is two", "this cannot be three", "why is this not three", "no numbers here"};

    int maxSentences = sizeof(txt) / sizeof(txt[0]);

    SaveInOrder(txt, maxSentences);

    return 0;
}
