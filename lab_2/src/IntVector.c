#include "IntVector.h"

// Создание нового вектора c начальной вместимостью
IntVector* int_vector_new(size_t initial_capacity)
{
    IntVector* vector = (IntVector*)malloc(sizeof(IntVector));
    if (vector == NULL) {
        return NULL;
    }

    vector->data = (int*)malloc(sizeof(int) * initial_capacity);
    if (vector->data == NULL) {
        free(vector);
        return NULL;
    }

    vector->size = 0;
    vector->capacity = initial_capacity;

    return vector;
}

// Получение элемента по индексу
int int_vector_get_item(const IntVector* v, size_t index)
{
    if (index < v->size) {
        return v->data[index];
    }
    return 0;
}
// Изменение элемента вектора по индексу
void int_vector_set_item(IntVector* v, size_t index, int item)
{
    if (index < v->size) {
        v->data[index] = item;
    }
}

// Создание копии вектора
IntVector* int_vector_copy(const IntVector* v)
{
    IntVector* copy = int_vector_new(v->capacity);
    if (!copy) {
        return NULL;
    }
    for (size_t i = 0; i < v->size; i++) {
        copy->data[i] = v->data[i];
    }
    copy->size = v->size;
    return copy;
}

// Освобождение памяти, занятой вектором
void int_vector_free(IntVector* v)
{
    if (v != NULL) {
        free(v->data);
        free(v);
    }
}

// Получение текущей емкости вектора
size_t int_vector_get_capacity(const IntVector* v)
{
    return v->capacity;
}
// Увеличение емкости вектора до заданного
int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (new_capacity <= v->capacity) {
        return 0;
    }

    int* new_data = (int*)realloc(v->data, new_capacity * sizeof(int));

    if (new_data == NULL) {
        return -1;
    }

    v->data = new_data;
    v->capacity = new_capacity;

    return 0;
}
// Добавление элемента в конец вектора
int int_vector_push_back(IntVector* v, int item)
{
    if (v == NULL) {
        return -1;
    }

    if (v->size >= v->capacity) {
        int* new_data = (int*)realloc(v->data, v->size * 2 * sizeof(int));
        if (new_data == NULL) {
            return -1;
        }
        v->data = new_data;
        v->capacity = v->size * 2;
    }

    v->data[v->size] = item;
    v->size++;
    return 0;
}
// Удаление последнего элемена из вектора.
void int_vector_pop_back(IntVector* v)
{
    if (v->size > 0) {
        v->size--;
    }
}
// Уменьшение емкости вектора до его размера.
int int_vector_shrink_to_fit(IntVector* v)
{
    if (v == NULL) {
        return -1;
    }
    size_t new_capacity = v->size;
    int* new_data = (int*)realloc(v->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        return -1;
    }
    v->data = new_data;
    v->capacity = new_capacity;
    return 0;
}

// Изменение размера вектора до заданного
int int_vector_resize(IntVector* v, size_t new_size)
{
    if (v == NULL) {
        return -1;
    }

    if (new_size > v->capacity) {
        if (!int_vector_reserve(v, new_size)) {
            return -1;
        }
        for (size_t i = v->size; i < new_size; i++) {
            v->data[i] = 0;
        }
    } else if (new_size < v->size) {
        for (size_t i = v->size; i > new_size; i--) {
            v->data[i] = 0;
        }
    }
    v->size = new_size;
    return 0;
}
