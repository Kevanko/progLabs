#include "IntVector.h"

// Создание нового динамического массива целых чисел заданной начальной
// вместимостью
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

// Создание копии динамического массива целых чисел
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

// Освобождение памяти, занятой динамическим массивом целых чисел
void int_vector_free(IntVector* v)
{
    if (v->data) {
        free(v->data);
    }
    if (v) {
        free(v);
    }
}

// Получение элемента динамического массива целых чисел по индексу
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

// Изменение элемента динамического массива целых чисел по индексу
void int_vector_set_item(IntVector* v, size_t index, int item)
{
    if (!v) {
        return;
    }

    if (index < v->size) {
        v->data[index] = item;
    }
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
<<<<<<< HEAD
    if (v->size == v->capacity) {
        int* new_data = (int*)realloc(v->data, v->capacity * sizeof(int) * 2);
        if (!new_data) {
            return -1;
        }
        v->data = new_data;
        v->capacity *= 2;
=======

    if (v->size >= v->capacity) {
        int* new_data = (int*)realloc(v->data, v->size * 2 * sizeof(int));
        if (new_data == NULL) {
            return -1;
        }
        v->data = new_data;
        v->capacity = v->size * 2;
>>>>>>> 0363c1cce6ab8786ba59120f0270676829f1e57e
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
    v->capacity = v->size;
    v->data = new_data;
    return 0;
}

// Увеличение емкости вектора до заданного
int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (!v || !v->data) {
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
<<<<<<< HEAD
        int* new_data = (int*)realloc(v->data, new_size * sizeof(int));
        if (!new_data) {
            return -1;
        }
        v->data = new_data;
        v->capacity = new_size;
    } else if (v->size > new_size) {
        v->size = new_size;
    }

    for (; v->size < new_size;) {
        v->data[v->size] = 0;
        v->size++;
    }

=======
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
>>>>>>> 0363c1cce6ab8786ba59120f0270676829f1e57e
    return 0;
}

