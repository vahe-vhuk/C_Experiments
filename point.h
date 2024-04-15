#ifndef __ADD_C_
#define __ADD_C_

struct Point
{
    int x;
    int y;
    struct Point(*add)(struct Point*);
    void* add_memory;
    int add_size;

    struct Point(*sub)(struct Point*);
    void* sub_memory;
    int sub_size;
};


void construct(struct Point*, int, int);
void destruct(struct Point*);

#endif
