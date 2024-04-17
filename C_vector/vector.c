#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

#include "vector.h"

void* make_member_function(void* self, const char* fname) {

    char syscall[] = "python3 parse.py                                           ";

    unsigned long long adr = (unsigned long long)self;

    
    sprintf(syscall + 17, "%llu %s", adr, fname);

    system(syscall);

    FILE* file = fopen("./code.txt", "r");

    char* buffer = (char*)malloc(2000);
    int ind = 0;

    int tmp;

    while (fscanf(file, "%d", &tmp) == 1) {
        buffer[ind++] = tmp;
    }    
    void* x = mmap(NULL, ind + 5, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_SHARED, -1, 0);
    if (x == NULL) {
        printf("error");
    }


    int* p = (int*)x;
    *p = ind + 5;
    ++p;
    x = p;

    memcpy(x, buffer, ind + 1);

    free(buffer);

    return x;

}

void delete_member_function(void* ptr)
{
    int* p = (int*)ptr;
    --p;

    int size = *p;

    ptr = p;

    munmap(ptr, size);
}


int* alloc(int cnt, int size)
{
    return (int*)calloc(cnt, size);
}


void construct(struct vector* self)
{
    self->_size = 0;
    self->_cap = 0;
    self->_arr = NULL;
    
    self->ctor = (void(*)(int))make_member_function(self, "ctor");    
    self->dtor = (void(*)())make_member_function(self, "dtor");    
    self->copy_from = (void(*)(struct vector*))make_member_function(self, "copy_from");
    self->move_from = (void(*)(struct vector*))make_member_function(self, "move_from");    
    self->at = (int*(*)(int))make_member_function(self, "at");    
    self->front = (int*(*)())make_member_function(self, "front");    
    self->back = (int*(*)())make_member_function(self, "back");    
    self->begin = (int*(*)())make_member_function(self, "begin");    
    self->end = (int*(*)())make_member_function(self, "end");    
    self->empty = (int(*)())make_member_function(self, "empty");    
    self->size = (int(*)())make_member_function(self, "size");    
    self->capacity = (int(*)())make_member_function(self, "capacity");    
    self->reserve = (void(*)(int))make_member_function(self, "reserve");    
    self->clear = (void(*)())make_member_function(self, "clear");    
    self->push_back = (void(*)(int))make_member_function(self, "push_back");    
    self->pop_back = (void(*)())make_member_function(self, "pop_back");    
    self->swap = (void(*)(struct vector*))make_member_function(self, "swap");    

    self->allocate = alloc;    
    self->free = free;    
    


       
    system("rm ./*.txt ./*.o");
}

void destruct(struct vector* self)
{
    delete_member_function((void*)self->ctor);
    delete_member_function((void*)self->dtor);
    delete_member_function((void*)self->copy_from);
    delete_member_function((void*)self->move_from);
    delete_member_function((void*)self->at);
    delete_member_function((void*)self->front);
    delete_member_function((void*)self->back);
    delete_member_function((void*)self->begin);
    delete_member_function((void*)self->end);
    delete_member_function((void*)self->empty);
    delete_member_function((void*)self->size);
    delete_member_function((void*)self->capacity);
    delete_member_function((void*)self->reserve);
    delete_member_function((void*)self->clear);
    delete_member_function((void*)self->push_back);
    delete_member_function((void*)self->pop_back);
    delete_member_function((void*)self->swap);


}



