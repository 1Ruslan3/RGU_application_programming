#include <stdio.h> 

void print_matrix(size_t rows, size_t cols, const int matrix[rows][cols]) {
    for (size_t i = 0; i < rows; ++i) {
        const int *row = *(matrix + i);
        for (const int *p = row; p < row + cols; ++p)
            printf("%d ", *p);
        printf("\n");
    }
}

const int *find_matrix_max(size_t rows, size_t cols, const int matrix[rows][cols], size_t *max_row, size_t *max_col) {
    const int *max = matrix;
    *max_row = 0;
    *max_col = 0;

    for (size_t i = 0; i < rows; ++i) {
        const int *row = *(matrix + i);
        for (const int *p = row; p < row + cols; ++p){
            if (*p > *max) {
                max = p;
                *max_row = (size_t)i;
                *max_col = (size_t)(p - row);
            }
        }
    }
    return max;
}

int main() {

    int data[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    size_t i;
    size_t j;
    const int * max = find_matrix_max(3, 3, data, &i, &j);

    print_matrix(3, 3, data);

    printf("\nmax = %d, row = %d, col = %d\n", *max, i, j);

    return 0;
}