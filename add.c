#include "point.h"


struct Point add(struct Point* rhv)
{
    struct Point* self = (struct Point*)ADDRESS;

    struct Point tmp;
    
    tmp.x = self->x + rhv->x;
    tmp.y = self->y + rhv->y;

    return tmp;   
} 
