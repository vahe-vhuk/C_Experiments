#include <stdio.h>
#include "vector.h"


void print(const char* s, struct vector* ob) {
    printf("%s ", s);
    for (vector_iterator it = ob->begin(); it != ob->end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
}

int main()
{

    struct vector ob;
    construct(&ob);

    ob.ctor(2);



    *ob.at(0) = 3;
    *ob.at(1) = 8;

    printf("%d, %d\n", *ob.at(0), *ob.at(1));

    printf("size = %d, cap = %d\n", ob.size(), ob.capacity());

    ob.push_back(10);

    
    printf("%d\n", *ob.at(2));

    printf("%d, %d\n", *ob.at(0), *ob.at(1));

    printf("size = %d, cap = %d\n", ob.size(), ob.capacity());



    for (vector_iterator it = ob.begin(); it != ob.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");

    int size = 0;

    scanf(" %d ", &size);

    for (int i = 0; i < size; ++i) {
        int tmp;
        scanf(" %d", &tmp);
        ob.push_back(tmp);
    }


    printf("size = %d, cap = %d\n", ob.size(), ob.capacity());

    *ob.at(3) = 15;

    print("ob = ", &ob);


    struct vector ob1;
    construct(&ob1);

    ob1.copy_from(&ob);

    
    printf("after copy\n");
    print("ob = ", &ob);
    print("ob1 = ", &ob1);
    
    struct vector ob2;
    construct(&ob2);

    ob2.move_from(&ob);

    printf("after move ob to ob2\n");

    print("ob = ", &ob);
    print("ob1 = ", &ob1);
    print("ob2 = ", &ob2);

    printf("after clear ob2\n");

    ob2.clear();

    print("ob = ", &ob);
    print("ob1 = ", &ob1);
    print("ob2 = ", &ob2);

    ob.dtor();
    ob1.dtor();
    ob2.dtor();


    destruct(&ob);
    destruct(&ob1);
    destruct(&ob2);

    return 0;
}
