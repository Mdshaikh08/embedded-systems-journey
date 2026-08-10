#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#define BUF_SIZE 8

typedef struct {
    int data[BUF_SIZE];
    int head;
    int tail;
    int count;
}CircularBuffer;


void cb_init(CircularBuffer *cb);
int cb_is_full(CircularBuffer *cb);
int cb_is_empty(CircularBuffer *cb);
int cb_enqueue(CircularBuffer *cb , int val);
int cb_dequeue(CircularBuffer *cb , int *val);



#endif