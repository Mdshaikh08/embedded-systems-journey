#include<stdio.h>


// Level 1 //
/*
void swap (int *p1 , int *p2){
 int temp = *p1;
 *p1 = *p2;
 *p2 = temp;
}


int main(){
int a = 2 , b = 3;
int *p1 = &a , *p2 = &b;

swap(p1 , p2);
printf("%d %d \n " , a , b);

}
*/



// Level 2 //
/*
void swap(char **p11 , char **p22){
    char *temp = *p11;
    *p11 = *p22;
    *p22 = temp;

    // printf("%s " , p1);
}

int main(){
    char *p1 = "hello";
    char *p2 = "world";
    swap(&p1 , &p2);
    printf("%s " , p1 );

   

}
    */


//  level 3 //

void swap (void * , void * , size_t);
int main(){
    int a = 2 ,  b = 3;
    swap(&a , &b , sizeof(int));
    printf(" %d %d " , a , b);

   
}

void swap(void *a , void *b , size_t size){
   char temp;
   char *pa = (char *)a;
   char *pb = (char *)b;

   for (size_t i = 0; i < size; i++){
      temp = pa[i];
       pa[i] = pb[i];
      pb[i] = temp;
   }
}