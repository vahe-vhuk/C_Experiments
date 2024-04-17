#include "../vector.h"


void dtor()
{
    struct vector* self = (struct vector*)ADDRESS;

    self->clear();

    // destruct(self);  
}
