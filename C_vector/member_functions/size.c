#include "../vector.h"

int size()
{
    struct vector* self = (struct vector*)ADDRESS;

    return self->_size;
}
