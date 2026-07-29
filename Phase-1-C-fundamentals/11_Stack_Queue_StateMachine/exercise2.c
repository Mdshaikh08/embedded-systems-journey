#include<stdio.h>

#define Queue_Size 8

typedef struct {
    int queue[Queue_Size];
    int front ;
    int rear;
    int count ;
}queue;


void queue_init(queue *q);
int queue_enqueue(queue *q , int value);
int queue_is_full(queue *q);
int queue_dequeue(queue *q , int *out);
int queue_is_empty(queue *q);



int main(void) {
    queue q;
    queue_init(&q);

    for (int i = 1; i <= 10; i++) {
        int ok = queue_enqueue(&q, i * 10);
        printf("enqueue %d: %s\n", i * 10, ok ? "ok" : "FULL");
    }
    

    int val;
    while (queue_dequeue(&q, &val)) {
        printf("dequeued: %d\n", val);
    }
   
}


void queue_init(queue *q){
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}


int queue_enqueue(queue *q , int value){
    if (queue_is_full(q))
    {
        return 0;
    }
    
    q->queue[q->rear] = value;
    q->count++;
    q->rear = ((q->rear) + 1) % Queue_Size;

    return 1;
   
}

int queue_is_full(queue *q){
    if (q->count == Queue_Size)
    {
        return 1;
    }
    
    return 0;
}

int queue_dequeue(queue *q , int *out){
    if (queue_is_empty(q))
    {
        return 0;
    }

     *out = q->queue[q->front];
     q->front = ((q->front) + 1) % Queue_Size;
     q->count--;


     return 1;
    
}


int queue_is_empty(queue *q){
    if (q->count == 0)
    {
        return 1;
    }
    return 0;
    
}