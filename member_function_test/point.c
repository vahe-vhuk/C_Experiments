#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

#include "point.h"

struct info
{
    int size;
    void* mem;
};

struct info make_member_function(void* self, const char* fname) {

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
    void* x = mmap(NULL, ind + 1, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);

    memcpy(x, buffer, ind + 1);

    
    struct info ob;
    ob.size = ind + 1;
    ob.mem = x;

    free(buffer);

    return ob;

}

void set_sub_ptr(struct Point* self)
{
    
    // unsigned long long adr = (unsigned long long)self;

    // char syscall[] = "gcc ./sub.c -c -DADDRESS=                              ";

    // sprintf(syscall + 25, "%llu", adr);

    // system(syscall);

    // system("objdump -d ./sub.o | awk '/<_sub>/,/^$/' > ./dump.txt");


    struct info inf = make_member_function(self, "sub");

    self->sub_memory = inf.mem;
    self->sub = (struct Point (*)(struct Point*))self->sub_memory;
    self->sub_size = inf.size;

}

void set_add_ptr(struct Point* self)
{

    struct info inf = make_member_function(self, "add");

    self->add_memory = inf.mem;
    self->add = (struct Point (*)(struct Point*))self->add_memory;
    self->add_size = inf.size;

}




void construct(struct Point* self, int x, int y)
{

    self->x = x;
    self->y = y;

    set_add_ptr(self);    
    set_sub_ptr(self);    
   
    system("rm ./*.txt ./*.o");
}

void destruct(struct Point* self)
{
    self->x = 0;
    self->y = 0;

    self->add = NULL;
    munmap(self->add_memory, self->add_size);
    self->add_memory = NULL;
    self->add_size = 0;


    munmap(self->sub_memory, self->sub_size);
    self->sub_memory = NULL;
    self->sub_size = 0;
}


