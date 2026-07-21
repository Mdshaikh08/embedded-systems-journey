#include<stdio.h>
  int* find_first_negative(int* , int);
int main(){
     int arr[] = {3, 7, -2, 5, -8, 1};
     int *point = find_first_negative(arr , 6);
  
    if (point != NULL)      
    {
        printf("the neg no was %d which is at index %ld",*point , point - arr);
    }
    
}


int* find_first_negative(int* arr , int n){
      int *last_elem = arr + (n -1);
      while (arr <= last_elem)
      {
        if(*arr < 0){
            return arr;
        }
        arr++;
      }
      return NULL;
      
}