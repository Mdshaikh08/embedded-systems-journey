#include<stdio.h>
#include<stdlib.h>


typedef struct
{
  int *data;
  int size;
  int capacity;

}dynamicarr;


void darr_init(dynamicarr * , int);
void darr_push(dynamicarr * , int);
void darr_print(dynamicarr *);
void darr_free(dynamicarr *);

int main(){
    dynamicarr darr; 
    darr_init(&darr , 2);

    for (int i = 1; i <= 10; i++)
    {
        darr_push(&darr , i*10);
        printf("After push %d : size = %d and capacity = %d\n" , i*10 , darr.size , darr.capacity);
    }

    darr_print(&darr);
    darr_free(&darr);
    
}


void darr_init(dynamicarr *strptr , int cap){
  strptr ->data = malloc(cap*sizeof(int)); 
  strptr ->capacity = cap;
  strptr->size = 0;
}


void darr_push(dynamicarr *strptr , int data_value){
   if (strptr->size == strptr->capacity)
   {
       strptr->capacity *=2;
    strptr->data = realloc(strptr->data , strptr->capacity*sizeof(int));
   }

    strptr->data[strptr->size] = data_value;
    strptr->size++;

}

void darr_print(dynamicarr *strptr){
  int i = 0;
  while(i < strptr->size){
    printf("%d " , strptr->data[i]);
    i++;
  }
}


void darr_free(dynamicarr *strptr){
  free(strptr->data);
  // printf("%d " , strptr->data[0]);
  strptr->data = NULL;
  strptr->capacity = 0;
  strptr->size = 0;
}



