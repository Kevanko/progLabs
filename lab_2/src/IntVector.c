#include "IntVector.h"

// Создание нового вектора
IntVector* int_vector_new(size_t initial_capacity)
{
    IntVector* v = (IntVector*)malloc(sizeof(IntVector));
    if (!v) {
        return NULL;
    }
    v->data = (int*)malloc(sizeof(int) * initial_capacity);
    if (!v->data) {
        free(v);
        return NULL;
    }
    v->capacity = initial_capacity;
    v->size = 0;
    return v;
}

// Создание копии вектора
IntVector* int_vector_copy(const IntVector* v)
{
    if (!v) {
        return NULL;
    }
    IntVector* v2 = int_vector_new(v->capacity);
    if (!v2) {
        return NULL;
    }
    for (int i = 0; i < v->size; i++) {
        v2->data[i] = v->data[i];
        v2->size++;
    }
    return v2;
}

// Освобождение памяти, вектором
void int_vector_free(IntVector* v)
{
    if (v) {
        free(v->data);
        free(v);
    }
}

// Получение элемента вектора по индексу
int int_vector_get_item(const IntVector* v, size_t index)
{
    if (!v) {
        return 0;
    }
    if (index < v->size) {
        return v->data[index];
    }
    return 0;
}

// Изменение элемента вектора по индексу
void int_vector_set_item(IntVector* v, size_t index, int item)
{
    if (!v) {
        return;
    }

    if (index < v->size) {
        v->data[index] = item;
    }
}

// Получение текущего размера вектора
size_t int_vector_get_size(const IntVector* v)
{
    if (!v) {
        return 0;
    }
    return v->size;
}

// Получение текущей емкости вектора
size_t int_vector_get_capacity(const IntVector* v)
{
    if (!v) {
        return 0;
    }
    return v->capacity;
}
// Добавление элемента в конец вектора
int int_vector_push_back(IntVector* v, int item)
{
    if (!v) {
        return -1;
    }
    if (v->size == v->capacity) {
        if (!v->capacity) {
            v->capacity = 1;
        }
        int* new_data = (int*)realloc(v->data, v->capacity * sizeof(int) * 2);
        if (!new_data) {
            return -1;
        }
        v->data = new_data;
        v->capacity *= 2;
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
}
// Удаление последнего элемена из вектора.
void int_vector_pop_back(IntVector* v)
{
    if (!v) {
        return;
    }
    if (v->size > 0) {
        v->size--;
    }
}
// Уменьшение емкости вектора до его размера.
int int_vector_shrink_to_fit(IntVector* v)
{
    if (!v || !v->size) {
        return -1;
    }
    if (v->capacity == v->size) {
        return 0;
    }
    int* new_data = (int*)realloc(v->data, v->size * sizeof(int));

    if (!new_data) {
        return -1;
    }

    v->data = new_data;
    v->capacity = v->size;
    return 0;
}

// Увеличение емкости вектора до заданного
int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (!v) {
        return -1;
    }
    if (new_capacity <= v->capacity) {
        return 0;
    }

    int* new_data = (int*)realloc(v->data, new_capacity * sizeof(int));

    if (!new_data) {
        return -1;
    }

    v->data = new_data;
    v->capacity = new_capacity;

    return 0;
}
// Изменение размера вектора до заданного
int int_vector_resize(IntVector* v, size_t new_size)
{
    if (!v) {
        return -1;
    }
    if (new_size > v->capacity) {
        int* new_data = (int*)realloc(v->data, new_size * sizeof(int));
        if (!new_data) {
            return -1;
        }
        v->data = new_data;
        v->capacity = new_size;
    }

    for (; v->size < new_size;) {
        v->data[v->size] = 0;
        v->size++;
    }

    return 0;
}

void print_vector(IntVector* v, char* text)
{
    static int counter = 1;
    if (counter == 1) {
        printf(" #\t\t\tName\t\t Size\t Capacity\t Array\n");
    }
    printf("%2d %30s \t| %ld\t| %ld\t | {",
           counter++,
           text,
           v->size,
           v->capacity);
    for (size_t i = 0; i < v->size && i < 30; i++) {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("}\n");
}
