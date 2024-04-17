#include "../vector.h"


void ctor(int n)
{
    
    struct vector* self = (struct vector*)ADDRESS;
    assert(self->_arr == NULL);

    self->_size = n;
    self->_cap = n;
    self->_arr = (int*)calloc(n, sizeof(int));
}
