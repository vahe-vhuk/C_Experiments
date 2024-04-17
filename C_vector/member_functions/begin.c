#include "../vector.h"

int* begin()
{
    struct vector* self = (struct vector*)ADDRESS;

    return self->_arr;
}
