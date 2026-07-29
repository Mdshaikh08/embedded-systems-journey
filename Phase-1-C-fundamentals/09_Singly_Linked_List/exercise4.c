#include <stdio.h>

#define QUEUE_SIZE 10


typedef struct EventNode {
    int event_id;
    struct EventNode *next;
} EventNode;


static EventNode pool[QUEUE_SIZE];
static EventNode *free_list_head = NULL;
static EventNode *queue_head = NULL;
static EventNode *queue_tail = NULL;


void init_pool(void) {
    for (int i = 0; i < QUEUE_SIZE - 1; i++) {
        pool[i].next = &pool[i + 1];
    }
    pool[QUEUE_SIZE - 1].next = NULL;
    free_list_head = &pool[0];
}


EventNode *alloc_block(void) {
    if (free_list_head == NULL) {
        return NULL; 
    }
    EventNode *b = free_list_head;
    free_list_head = free_list_head->next;
    return b;
}

void free_block(EventNode *b) {
    if (b == NULL) return;
    b->next = free_list_head;
    free_list_head = b;
}

int event_enqueue(int event_id) {
    EventNode *b = alloc_block();
    if (b == NULL) {
        return -1; 
    }

    b->event_id = event_id;
    b->next = NULL;

    if (queue_tail == NULL) {
        queue_head = b;
    } else {
        queue_tail->next = b;
    }
    queue_tail = b;

    return 0; 
}

int event_dequeue(void) {
    if (queue_head == NULL) {
        return -1; 
    }

    EventNode *b = queue_head;
    int id = b->event_id;
    queue_head = queue_head->next;

    if (queue_head == NULL) {
        queue_tail = NULL;
    }

    free_block(b);

    return id;
}

int main(void) {
    init_pool();

    event_enqueue(100);
    event_enqueue(101);
    event_enqueue(102);
    event_enqueue(103);
    event_enqueue(104);

    int id;
    while ((id = event_dequeue()) != -1) {
        printf("Processed event: %d\n", id);
    }

    return 0;
}






