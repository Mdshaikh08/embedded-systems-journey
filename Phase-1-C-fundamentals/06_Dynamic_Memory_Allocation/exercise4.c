#include<stdio.h>
#include<stdlib.h>

void allocate_array(int **double_arrp,int n){//we have been given the address of a pointer pointing to an int
     *double_arrp = calloc(n , sizeof(int));
     for (int i = 0; i < n; i++)
     {
        (*double_arrp)[i] = i * 10;
     }
     
}

void free_array(int **double_arrp){
    free(*double_arrp);
    *double_arrp = NULL;
}

int main() {
 
    int *arr = NULL;
    int n = 5;

    allocate_array(&arr, n);
    for (int i = 0; i < n; i++)         
    {
        printf("%d " , arr[i]);
    }
    


    free_array(&arr);
     printf("%p\n", arr);
}
