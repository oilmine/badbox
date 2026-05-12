#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "File not specified.\n");
        return 1;
    }

    FILE *pFile = fopen(argv[1], "r");

    if (pFile == NULL) {
        fprintf(stderr, "No such file.\n");
        return 1;
    }

    int count;

    int lines = 0;
    int words = 0;
    int chars = 0;

    int inWord = 0;

    while ((count = fgetc(pFile)) != EOF) {
        chars++;
        if (count == '\n') {
            lines++;
        }

        if (isspace(count)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(pFile);

    printf("Lines- %d\n", lines);
    printf("Words- %d\n", words);
    printf("Characters- %d\n", chars);

    return 0;
}