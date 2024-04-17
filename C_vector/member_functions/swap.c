#include "../vector.h"

void swap(struct vector* rhv)
{
    struct vector* self = (struct vector*)ADDRESS;

    int tmp = self->_size;
    self->_size = rhv->_size;
    rhv->_size = tmp;

    tmp = self->_cap;
    self->_cap = rhv->_cap;
    rhv->_cap = tmp;

    int* p = self->_arr;
    self->_arr = rhv->_arr;
    rhv->_arr = p;
}
