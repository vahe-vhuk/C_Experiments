#include "../vector.h"

void pop_back()
{
    struct vector* self = (struct vector*)ADDRESS;

    if (self->_size > 0) {
        --self->_size;
    }
}
