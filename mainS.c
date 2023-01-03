#include<stdio.h>
#include "isort.h"

#define SIZE 50

int main() {

    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
        scanf("%i", &arr[i]);

    insertion_sort(arr, SIZE);

    for (int i = 0; i < SIZE; i++) {
        if (i < SIZE - 1) {
            printf("%d,", *(arr + i));
        } else if (i == SIZE - 1) {
            printf("%d", *(arr + i));
        }
    }

    printf("\n");

    return 0;
}