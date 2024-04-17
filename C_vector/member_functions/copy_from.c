#include "../vector.h"

void copy_from(struct vector* rhv)
{
    struct vector* self = (struct vector*)ADDRESS;

    if (self == rhv) {
        return;
    }

    self->clear();

    self->_size = rhv->_size;
    self->_cap = rhv->_cap;

    for (int i = 0; i < self->_size; ++i) {
        self->_arr[i] = rhv->_arr[i];
    }
}
