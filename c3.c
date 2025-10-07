#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHIFT 3

void cezar(void) {
    char str[] = "HeLLo WoRld 1234 z";

    for (int idx = 0; str[idx] != '\0'; idx++) {
        if (str[idx] >= 'a' && str[idx] <= 'z') {
            str[idx] = ((str[idx] - 'a' + SHIFT) % 26) + 'a';
        } else if (str[idx] >= 'A' && str[idx] <= 'Z') {
            str[idx] = ((str[idx] - 'A' + SHIFT) % 26) + 'A';
        }
    }

    printf("%s\n", str);
}

int main(int argc, char *argv[]) {
    int min = 1000;
    int max = 0;
    int sum = 0;

    if (strcmp(argv[1], "min") == 0) {
        for (int idx = 2; idx < argc; idx++) {
            if (atoi(argv[idx]) < min) {
                min = atoi(argv[idx]);
            }
        }
        printf("minimum: %d\n", min);
    } else if (strcmp(argv[1], "max") == 0) {
        for (int idx = 2; idx < argc; idx++) {
            if (atoi(argv[idx]) > max) {
                max = atoi(argv[idx]);
            }
        }
    } else if (strcmp(argv[1], "sum") == 0) {
        for (int idx = 2; idx < argc; idx++) {
            sum += atoi(argv[idx]);
        }
    }
}
