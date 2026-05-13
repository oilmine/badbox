#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: head [LINES] [FILE]");
        return 1;
    }

    char buffer[1024] = {0};
    char *pFileName = argv[2];
    int count = atoi(argv[1]);
    int lines = 0;

    FILE *pFile = fopen(pFileName, "r");

    if (pFile == NULL) {
        fprintf(stderr, "No such file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pFile) && lines < count) {
        printf("%s", buffer);
        lines++;
    }

    fclose(pFile);
    return 0;
}