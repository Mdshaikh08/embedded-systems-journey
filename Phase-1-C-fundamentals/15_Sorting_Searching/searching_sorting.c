#include<stdio.h>


void bubble_sort(int arr[] , int n);
void insertion_sort(int arr[] , int n);
void merge_sort(int arr[] , int l , int r);
void merge(int arr[] , int l , int mid , int r );
int linear_search(int arr[] , int n , int target);
int binary_search(int arr[] , int n , int target);



int main(){
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int n1 = 6;
    bubble_sort(arr1 , n1);

    int arr2[] = {8, 3, 7, 4, 1};
    int n2 = 5;
    insertion_sort(arr2, n2);

    int arr3[] = {10, 4, 8, 2, 6, 1, 9};
    int n3 = 7;

    merge_sort(arr3 , 0 , n3 - 1);

    int idx1 = linear_search(arr3, n3, 8);
    int idx2 = binary_search(arr3, n3, 8);
}


void bubble_sort(int arr[] , int n){
   int temp = 0 ;
   for(int i = 0; i < n-1 ; i++){
      for(int j = 0; j < (n-1) - i ; j++){
         if(arr[j] > arr[j+1]){
          temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
         }
      }
   }   
}


void insertion_sort(int arr[] , int n){
   int key;
   int j;
   for(int i = 1 ; i < n ; i++){
      key = arr[i];
      j = (i-1);
      while(j >= 0 && key < arr[j]){
         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = key;
      
   }
}

void merge_sort(int arr[] , int l , int r){
   if(l < r){
      int mid = l + (r-l)/2;

      merge_sort(arr , l , mid);
      merge_sort(arr , mid+1 , r);
      merge(arr , l , mid , r);

   }
}


void merge(int arr[] , int l , int mid , int r){
   int left = l;
   int right = mid + 1;
   int merge_filler = 0;
   int total_elems = r-l+1;
   int merge_arr[total_elems];

   while(left <= mid && right <= r){
      if(arr[left] <= arr[right]){
         merge_arr[merge_filler] = arr[left];
         merge_filler++;
         left++;
      }
      else{
         merge_arr[merge_filler] = arr[right];
         merge_filler++;
         right++;
      }

   }
   if(left > mid){
      while(right <= r){
         merge_arr[merge_filler] = arr[right];
         merge_filler++;
         right++;
      }
   }
   else{
      while(left <= mid){
         merge_arr[merge_filler] = arr[left];
         merge_filler++;
         left++;
      }

   }

for (int j = 0; j < merge_filler; j++) {
   arr[l + j] = merge_arr[j];
}

}

int linear_search(int arr[] , int n , int target){

   for(int i = 0 ; i < n ; i++){
      if(arr[i] == target){
         return i;
      }
   }
   return -1;
}

int binary_search(int arr[] , int n , int target){

   if(target > arr[n-1] || target < arr[0]) return -1;

   int first = 0;
   int last = n-1;
   int mid;

   while(first <= last){
      mid = (first + last)/2;
      if(arr[mid] == target) return mid;
      else if(target > arr[mid]) {
         first = mid+1;
        
      }
      else{
         last = mid-1;
         }
   }
   return -1;
}