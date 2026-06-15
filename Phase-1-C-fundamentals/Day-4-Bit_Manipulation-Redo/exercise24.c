#include<stdio.h>
#include<stdint.h>


int find_unique(int *arr , int n){
    int result = 0;
    for (int i = 0; i < n  ; i++)
    {
        result ^=  arr[i];
    }

    return result;
    
}

int main(){
    int arr[] = {1 , 2 , 3 , 2 , 1};
    int unique = find_unique(arr , 5);
    printf("%d" , unique);
}