#include <stdio.h>
#include "isort.h"

#define size 50

int main() {
    int i = 0;
    int arr[size] = {0};
    int num = 0;
    for (i = 0; i < size; i++) {
        printf("please enter a number, this number is %d/50 \n", i + 1);
        scanf("%d", &num);
        *(arr + i) = num;
    }
    insertion_sort(arr, size);
    for (i = 0; i < size; i++) {
        printf("%d,", *(arr + i));
    }
}