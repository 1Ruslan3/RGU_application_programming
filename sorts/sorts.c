#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int *arr, size_t size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - 1 - i; ++j)
            if (*(arr + j) > *(arr + j + 1))
                swap(arr + j, arr + j + 1);
}

void insertion_sort(int *arr, size_t size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        if (arr[i - 1] <= key)
            continue;

        int j;
        for (j = i - 1; j >= 0 && *(arr + j) > key; j--) {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int j = left;
    int i = j - 1;

    while (j < right) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }

    swap(&arr[i + 1], &arr[right]);

    return i + 1;
}

void quick_sort(int *arr, int left, int right) {
    if (left >= right) return;

    int p = partition(arr, left, right);

    quick_sort(arr, left, p - 1);

    quick_sort(arr, p + 1, right);
}