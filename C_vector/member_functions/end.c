#include "../vector.h"

int* front()
{
    struct vector* self = (struct vector*)ADDRESS;

    return self->_arr + self->_size;
}
