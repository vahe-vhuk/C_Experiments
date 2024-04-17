#include "../vector.h"

void clear()
{

    struct vector* self = (struct vector*)ADDRESS;

    self->_size = 0;
    self->_cap = 0;

    if (self->_arr) {
        free(self->_arr);
    }


  
}
