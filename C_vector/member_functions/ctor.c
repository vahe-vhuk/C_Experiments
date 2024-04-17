#include "../vector.h"
#include <unistd.h>
#include <sys/mman.h>

void ctor(int n)
{
    
    struct vector* self = (struct vector*)ADDRESS;
    assert(self->_arr == NULL);

    self->_size = n;
    self->_cap = n;
    self->_arr = self->allocate(n, sizeof(int));
}
