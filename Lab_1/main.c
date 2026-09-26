#include <stdio.h>

void print_array(const int *begin, const int *end) {
    for (const int *p = begin; p < end; ++p) {
        printf("%d", *p);
        if ((p + 1) < end) printf(" ");
    }
}

int *find_min(int *begin, int *end) {
    if (begin == end) return NULL;

    int *min_ptr = begin;
    for (int *p = begin + 1; p < end; ++p) 
        if (*p < *min_ptr) 
            *min_ptr = *p;

    return min_ptr;
}

long long sum_between(const int *first, const int *second) {
    if (first > second) {
        const int * tmp = first;
        first = second;
        second = tmp;
    }

    long long sum = 0;
    for (const int *p = first + 1; p < second; ++p) 
        sum += *p;
    return sum;
}


size_t find_longest_increasing(int *begin, int *end, int **sequence_begin) {
    if (begin == end) {
        *sequence_begin = NULL;
    }

    size_t current_lenght = 1;
    size_t max_lenght = 1;
    int *current_begin = begin;
    int *max_begin = begin;

    for (int * p = begin + 1; p < end; ++p) {
        if (*p > *(p - 1)){
            ++current_lenght;
        } else {
            current_lenght = 1;
            current_begin = p;
        }
        if (current_lenght > max_lenght) {
            max_lenght = current_lenght;
            max_begin = current_begin;
        }
    }
    *sequence_begin = max_begin;
    return max_lenght;
}

void reverse_range(int *begin, int *end) {
    if (begin == end) return;

    int * left = begin;
    int * rigth = end - 1;
    while (left < rigth) {
        int tmp = *left;
        *left = *rigth;
        *rigth = tmp;
        ++left;
        --rigth;
    }
}

int main()
{
    int arr[] = {1, 3, 5, 2, 8, 9, 11};
    reverse_range(arr, &arr[7]);
    print_array(arr, &arr[7]);
    int *s = NULL;
    int p = find_longest_increasing(arr, &arr[7], &s);

    printf("\n%d.  %d", p, *s);

    return 0;
}