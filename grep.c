#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        fprintf(stderr, "Usage: grep [TEXT] [FILE]");
        return 1;
    }

    char buffer[1024] = {0};
    char *pFileName = argv[2];
    char *text = argv[1];
    bool found = false;
    int lc = 1;

    FILE *pFile = fopen(pFileName, "r");

    if (pFile == NULL) {
        fprintf(stderr, "No such file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
        if (strstr(buffer, text)) {
            printf("%d: %s", lc, buffer);
            found = 1;
        }
        
        lc++;
    }

    if (!found) {
        printf("Text not in file.\n");
        return 1;
    }

    fclose(pFile);
    return 0;
}