#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    printf("%p\n%p\n", arr, ptr);
    *arr = 42;
    printf("%d\n", arr[0]);
    *ptr = 0;
    printf("%d\n", arr[0]);
    printf("%d\n", ptr[0]);
    printf("%p\n%p\n%p\n", arr, &arr[0], ptr);
    return 0;
}
