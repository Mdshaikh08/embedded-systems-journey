#include "Memory_Pool.h"

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
