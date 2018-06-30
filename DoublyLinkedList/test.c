#include <stdio.h>
#include "dllist.h"

void print(int i)
{
    printf("%d ", i);
}

int main(int argc, char const *argv[])
{
    dList dl = createDlist();

    for (int i = 0; i < 10; ++i)
        append(i, dl);
    printf("List: ");
    traverse(dl, print);
    printf("\n");

    delete(4, dl);
    printf("List: ");
    traverse(dl, print);
    printf("\n");
    deleteDlist(dl);

    return 0;
}
