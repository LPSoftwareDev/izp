#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_MAX_SIZE 100

int main() {

    // alokujte pamet pro prvni retezec
    char *first;
    first = malloc((CHAR_MAX_SIZE + 1) * sizeof(char));

    // zkontrolujte, zda se alokace podarila
    if (first == NULL) {
        return 1;
    }

    // zkopirujte retezec first do dalsiho retezce znak po znaku
    scanf("%100s", first);

    // pro druhy retezec alokujte pamet
    char *second;
    second = malloc((CHAR_MAX_SIZE + 1) * sizeof(char));

    if (second == NULL) {
        return 2;
    }

    strcpy(second, first);

    // oba retezce vypiste
    printf("first: %s\n", first);
    printf("second: %s\n", second);

    // oba retezce uvolnete z pameti
    free(second);
    free(first);

    return 0;
}
