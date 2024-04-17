#include "../vector.h"

int* back()
{
    struct vector* self = (struct vector*)ADDRESS;

    return self->_arr + self->_size - 1;
}
