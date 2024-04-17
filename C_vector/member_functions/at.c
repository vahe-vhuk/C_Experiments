#include "../vector.h"

int* at(int pos)
{
    struct vector* self = (struct vector*)ADDRESS;

    if (pos < 0 || pos >= self->_size) {
        return NULL;
    }
    return self->_arr + pos;
}
