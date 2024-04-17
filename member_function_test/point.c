#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

#include "point.h"

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
    void* x = mmap(NULL, ind + 5, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (x == NULL) {
        printf("error");
    }


    int* p = (int*)x;
    *p = ind + 5;

    x = p + 1;

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




void construct(struct Point* self, int x, int y)
{

    self->x = x;
    self->y = y;

    self->add = (struct Point(*)(struct Point*))make_member_function(self, "add");
    self->sub = (struct Point(*)(struct Point*))make_member_function(self, "sub");
    
    system("rm ./*.txt ./*.o");
}

void destruct(struct Point* self)
{
    self->x = 0;
    self->y = 0;

    delete_member_function((void*)self->add);
    delete_member_function((void*)self->sub);

}


