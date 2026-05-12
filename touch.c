#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("File not specified.\n");
        return 1;
    }

    FILE *pFile = fopen(argv[1], "w");
    if (pFile == NULL) {
        return 1;
    }

    fclose(pFile);
    return 0;
}