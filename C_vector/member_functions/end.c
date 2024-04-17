#include "../vector.h"

int* end()
{
    struct vector* self = (struct vector*)ADDRESS;

    return self->_arr + self->_size;
}
