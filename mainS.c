#include <stdio.h>
#include "isort.h"

#define size 50

int main() {

    int arr[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);

    }
    insertion_sort(arr, size);
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            printf("%d,", *(arr + i));
        } else if (i == size - 1) {
            printf("%d", *(arr + i));
        }
    }
    printf("\n");
    return 0;
}