#include "IntVector.h"

int main()
{
    IntVector* vector = int_vector_new(5);
    print_vector(vector, "(Vector) new vect <5>");

    int_vector_push_back(vector, 15);
    print_vector(vector, "(Vector) pushback <15>");

    IntVector* vector_copy = int_vector_copy(vector);
    print_vector(vector, "(Vector_copy) copy <Vector>");

    int_vector_push_back(vector, 23);
    print_vector(vector, "(Vector) pushback <23>");

    int_vector_pop_back(vector_copy);
    print_vector(vector_copy, "(Vector_copy) popback");

    int_vector_push_back(vector_copy, 11);
    print_vector(vector_copy, "(Vector_copy) pushback <11>");

    int_vector_shrink_to_fit(vector_copy);
    print_vector(vector_copy, "(Vector_copy) shrink");

    int_vector_resize(vector_copy, 10);
    print_vector(vector_copy, "(Vector_copy) resize <10>");

    int_vector_reserve(vector, 10);
    print_vector(vector, "(Vector) reserve <10>");

    int_vector_set_item(vector_copy, 5, 222);
    print_vector(vector_copy, "(vector_copy) set <5 : 222>");

    int_vector_free(vector);
    int_vector_free(vector_copy);
    return 0;
}
