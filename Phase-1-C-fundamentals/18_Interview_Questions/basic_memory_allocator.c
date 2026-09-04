#include<stdio.h>


#define POOL_SIZE 1024

static char pool[POOL_SIZE];
static size_t offset = 0;

void *bump_allocator(size_t size){

    if(offset + size > POOL_SIZE) return NULL;

    size_t start = offset;
    offset += size;

    return &pool[start];
};

int main(){
    
    void *ptr = NULL;
    ptr = bump_allocator(100);
}