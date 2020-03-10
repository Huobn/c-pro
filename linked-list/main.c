#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define SIZE 10

int main()
{
    struct LinkedList *list;
    int i,data;
    // create a linked list
    list = createList();

    /* test push */
    printf("[INFO]: Test API => push(list, data)\n");
    for ( i=0; i<SIZE; ++i ) {
        push(list, i);

    }
    __printList( list );
    printf("[INFO]: Test push done\n");

    /* test insert */
    printf("[INFO]: Test API => insert(list,index,data).\n");
    printf("[INFO]: Insert at 0 with number 100\n");
    insert(list, 0, 100);
    __printList( list );
    printf("[INFO]: Insert at 3 with number 500\n");
    insert(list, 3, 500);
    __printList( list );
     printf("[INFO]: Insert at tail with number 1000\n");
    insert(list, getSize(list), 1000);
    __printList( list );
    printf("[INFO]: Test insert done.\n");





    return 0;
}
