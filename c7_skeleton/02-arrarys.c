#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define INT_ARRAY_SIZE 5

/**
 * Funkce vytiskne obsah pole o velikosti size na obrazovku
 */
void printIntArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * Funkce vynasobi vsechny prvky pole arr konstantou c.
 */
// void arrMultConst(int* arr, int size, int c)
void arrMultConst(int arr[], int size, int c) {
    for (int idx = 0; idx < size; idx++) {
        arr[idx] = arr[idx] * c;
    }
}

/**
 * Funkce prevede vsechny znaky v retezci str na velka.
 * Lze pouzit funkci toupper z knihovny ctype.h
 */
// void changeCase(char* str);
void changeCase(char str[]) {
    int idx = 0;
    while (str[idx] != '\0') {
        str[idx] = toupper(str[idx]);
        idx++;
    }
}

/**
 * Funkce vyhleda podretezec substr v retezci str.
 * Pokud se podretezec ve funkci nachazi, funkce vrati index jeho zacatku.
 * Pokud se retezec ve funkci nenachazi, funkce vrati -1.
 */
int findSubstr(char str[], char substr[]) {
    int idx = 0;
    int substring_idx = 0;
    while (str[idx] != '\0') {
        if (substr[substring_idx] == '\0') {
            return idx - substring_idx;
        }
        if (str[idx] == substr[substring_idx]) {
            substring_idx++;
        }
        idx++;
    }
    return -1;
}

/**
 * Funkce vlozi do pole arr prvek item na pozici pos.
 * Po vlozeni posune ostatni prvky v poli, posledni prvek z pole odstrani.
 */
// 1, 2, 3, 4, 5
void insert(int arr[], int size, int item, int pos) {
    for (int idx = size - 1; idx >= pos; idx--) {
        arr[idx] = arr[idx - 1];
    }
    arr[pos] = item;
}

int main() {

    int array[5] = {1, 2, 3, 4, 5};
    char str[] = "Hello";

    int substr1 = findSubstr(str, "ell");
    int substr2 = findSubstr(str, "Hell");
    int substr3 = findSubstr(str, "abc");
    printf("substring_index: %d\n", substr1);
    printf("substring_index: %d\n", substr2);
    printf("substring_index: %d\n", substr3);

    printIntArray(array, 5);
    insert(array, 5, 99, 1);
    printIntArray(array, 5);

    return 0;
}
