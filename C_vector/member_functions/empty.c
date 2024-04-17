#include "../vector.h"

int empty()
{
    struct vector* self = (struct vector*)ADDRESS;

    return !self->_arr;
}
