#include<stdio.h>
#include<stdint.h>


#define POOL_SIZE 10

typedef struct block {
    int data;
    struct block *link;
}Block;


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

int main(){
    init_pool();
    Block *a = alloc_block();
    Block *b = alloc_block();   
    Block *c = alloc_block();
    Block *d = alloc_block();   
    Block *e = alloc_block();   
    Block *f = alloc_block();   
    Block *g = alloc_block(); 
    Block *h = alloc_block();
    Block *i = alloc_block();   
    Block *j = alloc_block();   
    Block *k = alloc_block();     
    Block *l = alloc_block();
    Block *m = alloc_block();
    printf("m is %s\n", m == NULL ? "NULL (pool exhausted)" : "valid");

    free_block(g);
    g = alloc_block(); 
    


   return 0;
}
