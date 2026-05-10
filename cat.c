#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "File not specified.");
        return 1;
    }

    char buffer[1024] = {0};
    char *pFileName = argv[1];
    FILE *pFile = fopen(pFileName, "r");
    
    if (pFile == NULL) {
        fprintf(stderr, "No such file.");
        return 1;
    }

    printf("\n");
    while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
        printf("%s", buffer);
    }

    fclose(pFile);
    return 0;
}