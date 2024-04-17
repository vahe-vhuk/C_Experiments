#include "../vector.h"

void clear()
{

    struct vector* self = (struct vector*)ADDRESS;

    self->_size = 0;
    self->_cap = 0;

    if (self->_arr) {
        self->free(self->_arr);
    }
    self->_arr = NULL;


  
}
