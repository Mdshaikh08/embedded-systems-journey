#include "utils.h"
#include "Ring_Buffer.h"

int main(){

    // Counter code
    printf("%d \n" , counter);

    increment_counter();
    increment_counter();
    increment_counter();

    printf("%d \n" , counter);


    //Ring Buffer code
     CircularBuffer cb;
    cb_init(&cb);

    for (int i = 1; i <= 10; i++)
    {
        int ok = cb_enqueue(&cb , i*10);
        printf("Enqueue %d: %s\n" , i*10 , ok ? "Ok" :"Full");
    }

    int val;
    while (cb_dequeue(&cb , &val))  
    {
        printf("%d " , val);
    }
    

}