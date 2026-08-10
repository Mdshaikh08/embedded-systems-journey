#include "Ring_Buffer.h"

void cb_init(CircularBuffer *cb){
    cb->tail = 0;
    cb->head = 0;
    cb->count = 0;
}

int cb_enqueue(CircularBuffer *cb , int val){
     if(cb_is_full(cb)){
        return 0;
     }

     cb->data[cb->head] = val;
     (cb->count)++;
     cb->head = ((cb->head + 1) % BUF_SIZE);

     return 1;
     
}

int cb_is_full(CircularBuffer *cb){
    if(cb->count == BUF_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

int cb_dequeue(CircularBuffer *cb , int *val){
    if (cb_is_empty(cb)){
            return 0;
    }

    *val = cb->data[cb->tail];

   cb->tail = ((cb->tail + 1) % BUF_SIZE);
   cb->count--;

    return 1;
}


int cb_is_empty(CircularBuffer *cb){
    if (cb->count == 0)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}