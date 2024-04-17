#include <stdio.h>
#include "vector.h"


int main()
{

    struct vector ob;
    construct(&ob);

    ob.ctor(2);

    // int size = 0;

    // scanf("%d", &size);

    // for (int i = 0; i < size; ++i) {
    //     int tmp;
    //     scanf("%d", &tmp);
    //     ob.push_back(tmp);
    // }


    // printf("size = %d, cap = %d", ob.size(), ob.capacity());

    // *ob.at(3) = 15;

    // for (vector_iterator it = ob.begin(); it != ob.end(); ++it) {
    //     printf("%d ", *it);
    // }





    return 0;
}
