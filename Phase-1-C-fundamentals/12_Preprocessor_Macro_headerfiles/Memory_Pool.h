#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

    //According to the right structure #includes comes first
#include<stdio.h>
#include<stdint.h>

   // The comes the Macros
#define POOL_SIZE 10

   // Then comes the Typedef and definitions 

typedef struct block {
    int data;
    struct block *link;
}Block;


  // Then comes the prototypes 


void init_pool(void);
Block *alloc_block(void);
void free_block(Block *b);






#endif