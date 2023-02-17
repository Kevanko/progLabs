#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    void** data;
    size_t size;
    size_t capacity;
} Vector;

Vector* init_vector(size_t initial_capacity)
{
    Vector* tmp = (Vector*)malloc(sizeof(Vector));

    if (!tmp)
        return NULL;

    tmp->data = (void**)malloc(initial_capacity * sizeof(void*));
    if (tmp->data == NULL) {
        free(tmp);
        return NULL;
    }

    tmp->size = 0;
    tmp->capacity = initial_capacity;

    return tmp;
}

int main(int argv, char** argc)
{
    for (int i = 1; i < argv; i++) {
        printf("[%s]\n", argc[i]);
    }
    Vector *arr = init_vector(60);
    
    return 0;
}
