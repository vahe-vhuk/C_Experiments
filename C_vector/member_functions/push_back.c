#include "../vector.h"


void push_back(int val)
{
    struct vector* self = (struct vector*)ADDRESS;

    if (self->_size >= self->_cap) {
        self->reserve(self->_cap ? self->_cap * 2 : 2);
    }

    self->_arr[self->_size] = val;
    ++self->_size;  
}
