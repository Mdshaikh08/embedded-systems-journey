#include<stdio.h>

void print_2d(int *, int , int );
int main(){
  int arr[3][4] = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12}
};
  print_2d((int *)arr, 3, 4);
}

void print_2d(int *arr, int rows, int cols){
     int *nextto_last_elem = arr + (rows * cols);
     
     
     printf("2D array = { ");

     while (arr < nextto_last_elem)
     {
        printf("%d, " , *arr);
        arr++;
     }
     printf("}");
     
}