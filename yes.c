#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
        while (1) {
            printf("\ny");
        }
    }
    
    if (argv[1] != NULL) {
        while (1) {
            printf("%s\n", argv[1]);
        }
    }   
}