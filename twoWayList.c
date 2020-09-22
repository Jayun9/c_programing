#include <stdarg.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;