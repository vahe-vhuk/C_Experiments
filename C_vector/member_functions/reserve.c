#include "../vector.h"


void reserve(int n)
{
    struct vector* self = (struct vector*)ADDRESS;

    if (self->_cap >= n) {
        return;
    }

    int* tmp = self->allocate(n, sizeof(int));

    for (int i = 0; i < self->_size; ++i) {
        tmp[i] = self->_arr[i];
    }

    if (self->_arr) {
        self->free(self->_arr);
    }

    self->_arr = tmp;
    self->_cap = n;
}
