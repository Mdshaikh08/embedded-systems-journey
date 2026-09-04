#include<stdio.h>

#define BUFFER_SIZE 10

typedef struct 
{
    int buffer[10];
    int head;
    int tail;
    int count;
}Buffer;

int enqueue(Buffer* buffer, int);
void buffer_init(Buffer *buffer);
int dequeue(Buffer *buffer);
int main(){

    Buffer buffer;
    buffer_init(&buffer);

    for(int i = 0; i < 10; i++){
    enqueue(&buffer,i*10);
    }

    dequeue(&buffer);
    dequeue(&buffer);
    dequeue(&buffer);
    enqueue(&buffer,10);
    enqueue(&buffer,10);

    printf("%d " , buffer.tail );
    printf("%d " , buffer.head );
}


void buffer_init(Buffer *buffer){
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
}

int enqueue(Buffer *buffer, int No){
    if(buffer->count == BUFFER_SIZE){
        return 0;
    }
    buffer->buffer[buffer->tail] = No;
    buffer->count++;
    buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;

    return 1;
}

int dequeue(Buffer *buffer){
    if(buffer->count == 0){
        return 0;
    }

    buffer->head = (buffer->head + 1) % BUFFER_SIZE;
    buffer->count--;

    return 1;
}