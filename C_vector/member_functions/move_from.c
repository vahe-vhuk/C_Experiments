#include "../vector.h"

void move_from(struct vector* rhv)
{
    struct vector* self = (struct vector*)ADDRESS;

    if (self == rhv) {
        return;
    }

    self->clear();

    self->_size = rhv->_size;
    self->_cap = rhv->_cap;
    self->_arr = rhv->_arr;

    rhv->_size = 0;
    rhv->_cap = 0;
    rhv->_arr = NULL;

  
}
