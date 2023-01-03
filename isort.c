void shift_element(int *arr, int index) {
    int temp1 = *(arr + 1), temp2;

    for (int j = 1; j <= index; j++) {
        temp2 = *(arr + j + 1);
        *(arr + j + 1) = temp1;
        temp1 = temp2;
    }
}

void insertion_sort(int *arr, int len) {
    int temp, count;

    for (int i = 1, j; i < len; i++) {
        count = 0;
        temp = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > temp) {
            count++;
            j = j - 1;
        }
        shift_element(arr + j, count);
        *(arr + j + 1) = temp;
    }
}