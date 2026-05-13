#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: mv [SOURCE] [DESTINATION]");
        return 1;
    }

    char buffer[1024] = {0};
    FILE *pSFile = fopen(argv[1], "r");
    if (pSFile == NULL) {
        fprintf(stderr, "No such file.");
        return 1;
    }

    FILE *pDFile = fopen(argv[2], "w");
    while (fgets(buffer, sizeof(buffer), pSFile) != NULL) {
        fprintf(pDFile, "%s", buffer);
    }

    fclose(pSFile);
    remove(argv[1]);
    fclose(pDFile);

    return 0;
}