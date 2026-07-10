#include<stdio.h>

void print_arrayN(int * , int);
void sum_arrayN(int * , int);
void find_max(int * , int);

int main(){
    int arrayN[] = {6,9,12,13,5,11};
    int arrL = 6;

    print_arrayN(arrayN , arrL);
    sum_arrayN(arrayN , arrL);
    find_max(arrayN , arrL);
}

void print_arrayN (int *arrayN , int arrL){
    int *last_elem = arrayN + (arrL - 1);
    printf("array = {");
    while(arrayN <= last_elem){
    printf(" %d " , *arrayN);
    arrayN++;
    }
    printf("} \n");
}

void sum_arrayN(int *arrayN, int arrL){
    int *last_elem = arrayN + (arrL-1);
    int sum = 0;
    while(arrayN <= last_elem){
        sum = sum + *arrayN;
        arrayN++;
    }
    printf("Sum of elements of array = %d \n" , sum);
}

void find_max(int *arrayN , int arrL){
    int *last_elem = arrayN + (arrL-1);
    int Max = *arrayN;
    arrayN++;
    while (arrayN <= last_elem)
    {
        if (*arrayN > Max)
        {
            Max = *arrayN;
        }
        arrayN++;
        
    }
    
    printf("max value from elements of array = %d \n", Max );
    
}