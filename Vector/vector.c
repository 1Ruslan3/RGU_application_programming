#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} Vector;

Vector *init(int volume) {

}

int clear(Vector *vector) {

}

int grow(Vector *vector) {

}

int append(Vector *vector, int item) {

}

int pop_back(Vector *vector, int *out) {

}

int get_item(Vector *vector, size_t index, int *out) {

}

int set_value(Vector *vector, size_t index, int item) {

}

int insert(Vector *vector, size_t index, int item) {

}

int remove_at(Vector *vector, size_t index, int *out) {

}
