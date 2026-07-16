#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


int main(){

    int *ptr1 = (int*)malloc(5 * sizeof(int) );

    for (int i = 0; i < 5; i++)
    {
        printf("%d " , ptr1[i]);
    }

    free(ptr1);


    int *prt2 = (int*)calloc(5 , sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("%d " , prt2[i]);

    }
    


    prt2 = realloc(prt2, 10*sizeof(int));

    for (int i = 5; i < 10; i++)
    {
        prt2[i] = 100 + (i - 5);
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d " , prt2[i]);
    }
    

    free(prt2);



    
        
}