#include <stdio.h>

#include "point.h"

void print(const char* s, struct Point* ob)
{
    printf("%sPoint(%d, %d)\n",s, ob->x, ob->y);
}


int main()
{

    struct Point ob1;
    construct(&ob1, 1, 2);

    
    struct Point ob2;
    construct(&ob2, 3, 4);


    struct Point ob3;
    construct(&ob3, 10, 11);

    

    struct Point ob4 = ob1.add(&ob2);
    struct Point ob5 = ob1.add(&ob3);
    struct Point ob6 = ob2.sub(&ob3);
    struct Point ob7 = ob3.sub(&ob1);
    struct Point ob8 = ob2.sub(&ob2);

    print("ob1 = ", &ob1);
    print("ob2 = ", &ob2);
    print("ob3 = ", &ob3);
    print("ob1 + ob2 = ", &ob4);
    print("ob1 + ob3 = ", &ob5);
    print("ob2 - ob3 = ", &ob6);
    print("ob3 - ob1 = ", &ob7);
    print("ob2 - ob2 = ", &ob8);


    destruct(&ob1);
    destruct(&ob2);
    destruct(&ob3);
    destruct(&ob4);

    return 0;
}
