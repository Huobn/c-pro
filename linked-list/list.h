#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct LinkedList{

    int _size;
    struct Node *_node;
};


/**
    print list
*/
void __printList(const struct LinkedList *list);

/**
    print node
*/
void __printNode( const struct Node *node );


/**
    get the tail node of list
*/
struct Node *_getTailNode( struct LinkedList *list );

/**
    get node
*/
struct Node *_getNode( struct LinkedList *list, int index );

/**
    create a list
*/
struct LinkedList* createList();

/**
    get the size of list
*/
extern int getSize( const struct LinkedList *list );

/**
    add a element to list
*/
extern int push(struct LinkedList *list, int data);

/**
    get a  element at specific index
*/
extern void get( struct LinkedList *list, int index ,int *data );
/**
    get the last element of list
*/
extern void pop( struct LinkedList *list, int *data );

/**
    Insert a element at specific index
*/
extern void insert( struct LinkedList *list, int index, int data );


void shift( struct LinkedList *list, int *data );


#endif // LIST_H_INCLUDED
