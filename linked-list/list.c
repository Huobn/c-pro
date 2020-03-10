#include "list.h"

#define NULL 0

void __printList( const struct LinkedList *list ) {

    if ( list != NULL  && list->_size > 0
        && list->_node != NULL ) {
        int size = list->_size;
        int i,data;
        printf("[ ");
        for ( i=0; i<size; ++i ) {
            get( list, i, &data );
            printf("%d ",  data);
        }
        printf("]\n");
    }else {
        printf("[]\n");
    }
}

void __printNode( const struct Node *node ) {

    if ( node != NULL ) {
        printf("Node{ data : %d ; id : %x }", node->data, node);
    }else {
        printf("Node{}");
    }
}


/**
@param : struct LinkedList*
@return : struct Node*
*/
struct Node* _getTailNode(struct LinkedList *list) {

    struct Node *node = NULL;

    if ( list != NULL && list->_size > 0
            && list->_node != NULL ) {
        node = list->_node->prev;
    }

    return node;

}

struct Node *_getNode( struct LinkedList *list, int index) {

    struct Node *ret = NULL;

    if ( list != NULL && index < list->_size
            && list->_node != NULL ) {
        struct Node *p = list->_node;
        int i;
        int size = list->_size;

        if ( index <= size / 2 ) {
            for ( i=0; i<index; ++i ) {
                p = p->next;
            }
        }else {
            for ( i=0; i<(size-index); ++i ) {
                p = p->prev;
            }
        }
        ret = p;
    }

    return ret;
}

/**
@param : null
@return : struct LinkedList*
Create a list
*/
struct LinkedList* createList() {

    struct LinkedList *list = (struct LinkedList*)malloc( sizeof( struct LinkedList ) );
    list->_size = 0;
    list->_node = NULL;

    return list;
}


/**
@param : struct LinkedList*
*/
int getSize(const struct LinkedList *list) {
    return list->_size;
}

int push(struct LinkedList *list, int data) {

    int flag = 1;
    struct Node *node; // new node
    struct Node *tail; // tail node
    void *p = malloc( sizeof( struct Node ) );

    if ( p != NULL ) {
        node = (struct Node*)p;
        node->data = data;
        if ( list->_node == NULL ) {
            node->prev = node;
            node->next = node;

            list->_node = node;
            list->_size++;
        }else {
            tail = _getTailNode( list );
            if ( tail != NULL ) {
                node->next = list->_node;
                list->_node->prev = node;

                node->prev = tail;
                tail->next = node;

                list->_size++;

            }else {
                flag = 0;
            }
        }

    }else {
        flag = 0;
    }

    return flag;
}

void get( struct LinkedList *list, int index, int *data ) {

    struct Node *p;
    p = _getNode( list, index );
    if ( p != NULL ) {
        *data = p->data;
    }
}

void pop( struct LinkedList *list, int *data ) {

    if ( list != NULL && list->_size > 0
        && list->_node != NULL ) {

        struct Node *tail = list->_node->prev;

        *data = tail->data;

        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;

        free( tail );

        list->_size--;
    }
}

void insert( struct LinkedList *list, int index, int data ) {

    if ( list == NULL || index > list->_size
        || index < 0 || list->_node == NULL ) return;

    if ( index == list->_size ){
        push( list, data );
    }else {
        struct Node *node;
        struct Node *p;
        void *r = malloc( sizeof( struct Node ) );

        if ( r == NULL ) return;

        node = ( struct Node*)r;

        node->data = data;

        p = _getNode(list, index);

        if ( p == NULL ) return;

        node->prev = p->prev;
        node->next = p;

        p->prev->next = node;
        p->prev = node;

        // header insert
        if ( p == list->_node ) list->_node = node;

        list->_size++;
    }

}

void shift( struct LinkedList *list, int *data ) {

    if ( list == NULL || list->_size <= 0
        || list->_node == NULL ) return;

    struct Node *first = list->_node;
    // change pointer
    first->prev->next = first->next;
    first->next->prev = first->prev;

    list->_node = first->next;

    *data = first->data;

    free( first );

    list->_size--;

}
