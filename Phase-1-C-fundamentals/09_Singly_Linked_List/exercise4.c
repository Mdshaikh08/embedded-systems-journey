#include<stdio.h>


#define QUEUE_SIZE 10
typedef struct event_node {
     int data;  // event_id
     struct event_node *link;
}EventNode;

static EventNode pool[QUEUE_SIZE];
static EventNode *free_list_head = NULL;






