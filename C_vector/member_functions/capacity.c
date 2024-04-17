#include "../vector.h"

int capacity()
{
    struct vector* self = (struct vector*)ADDRESS;

    return self->_cap;
}
