#include "Memory_Pool.h"

static Block pool[POOL_SIZE] ;
static Block *free_list_head = NULL;


void init_pool  (void){
    free_list_head = &pool[0];
    Block *temp = free_list_head;
    int n = 1;
    while (n < POOL_SIZE)
    {
        temp->link = &pool[n];
        temp = temp->link;
        n++;
    }
    if (n == 10)
    {
        temp->link = NULL;
    }
    
    
}

Block *alloc_block(void){
    if(free_list_head == NULL){
        return NULL;
    }
    Block *return_block = free_list_head;
    
    free_list_head = free_list_head->link;
    

    return_block->link = NULL;

    return return_block;


}

void free_block(Block *b){

    b->link = free_list_head;
    free_list_head = b;
    
}