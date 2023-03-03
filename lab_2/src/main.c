#include "IntVector.h"

int main()
{
    IntVector* vector = int_vector_new(sizeof(int) * 5);
    int_vector_push_back(vector, 15);

    IntVector* vector2 = int_vector_copy(vector);
    int_vector_push_back(vector2, 11);
    int_vector_set_item(vector2, 0, 5);

    for (int i = 0; i < vector->size; i++) {
        printf("%d", int_vector_get_item(vector, i));
    }
    printf("\n");
    for (int i = 0; i < vector2->size; i++) {
        printf("%d ", int_vector_get_item(vector2, i));
    }
    printf("\n");
    int_vector_free(vector);
    int_vector_free(vector2);
    return 0;
}
