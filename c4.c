#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

// NOTE: ./main 2> out = zapise stderr do suboru
// NOTE: ./main > out = zapise stdout do suboru

// NOTE: ./main > out 2>&1 = spoji steam stderr s stdout a zapise do souboru

// NOTE: echo "x" | ./main = pipe-ne echo do stdin mainu
// NOTE: scanf() returnuje EOF -> mozeme to nacitat cely stdin while

int get_sum(int[], int);
float get_avg(int[], int);
int get_min(int[], int);
int get_max(int[], int);
int get_nsn(int, int);
int get_nsd(int, int);

int get_sum(int arr[], int size) {
    int sum = 0;
    for (int idx = 0; idx < size; idx++) {
        sum += arr[idx];
    }
    return sum;
}

float get_avg(int arr[], int size) {
    int sum = get_sum(arr, size);
    return (float)sum / size;
}

int get_min(int arr[], int size) {
    int min = 1000;
    for (int idx = 0; idx < size; idx++) {
        if (arr[idx] < min) {
            min = arr[idx];
        }
    }
    return min;
}

int get_max(int arr[], int size) {
    int max = 0;
    for (int idx = 0; idx < size; idx++) {
        if (arr[idx] > max) {
            max = arr[idx];
        }
    }
    return max;
}

int in_set(int set[], int size, int elem);
int is_set(int set[], int size);

void print_union(int set1[], int size1, int set2[], int size2);
void print_inter(int set1[], int size1, int set2[], int size2);
void print_carte(int set1[], int size1, int set2[], int size2);

int in_set(int set[], int size, int elem) {
    for (int idx = 0; idx < size; idx++) {
        if (set[idx] == elem) {
            return 0;
        }
    }
    return 1;
}

int is_set(int set[], int size) {
    int temp[size];
    for (int idx = 0; idx < size; idx++) {
        if (in_set(temp, size, set[idx]) != 0) {
            temp[idx] = set[idx];
        } else {
            return 1;
        }
    }
    return 0;
}

#define SIZE 3

int main(void) {
    int set[SIZE] = {
        1,
        2,
        3,
    };

    int not_set[SIZE] = {2, 2, 3};

    printf("1 in set: %d\n", in_set(set, SIZE, 1));
    printf("set: %d\n", is_set(set, SIZE));
    printf("not set: %d\n", is_set(not_set, SIZE));
}
