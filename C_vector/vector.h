#ifndef __C__VECTOR__
#define __C__VECTOR__

#include <stdlib.h>
#include <assert.h>


typedef int* vector_iterator;

struct vector
{
    int _size;
    int _cap;
    int* _arr;


    void (*ctor)(int n);
    void (*dtor)();
    
    void (*copy_from)(struct vector*);
    void (*move_from)(struct vector*);

    int* (*at)(int);
    int* (*front)();
    int* (*back)();


    int* (*begin)();
    int* (*end)();

    int (*empty)();
    int (*size)();
    int (*capacity)();

    void (*reserve)(int n);
    void (*clear)();
    // void (*insert)(int, int);
    // void (*erase)(int);

    void (*push_back)(int);
    void (*pop_back)();

    // void (*resize)(int);

    void (*swap)(struct vector*);
};


void construct(struct vector*);
void destruct(struct vector*);

















#endif
