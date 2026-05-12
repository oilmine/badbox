#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
        while (true) {
            printf("\ny");
        }
    } else {
        while (true) {
            printf("%s\n", argv[1]);
        }
    }
}