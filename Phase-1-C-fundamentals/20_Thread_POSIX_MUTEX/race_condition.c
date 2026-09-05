#include<stdio.h>
#include <windows.h>

#define NO_INCREMENT 100000

int counter = 0;
CRITICAL_SECTION cs;

DWORD WINAPI increment_function(LPVOID arg) {

    for (int i = 0; i < NO_INCREMENT; i++) {
        EnterCriticalSection(&cs);
        counter++;
        LeaveCriticalSection(&cs);  
    }
    return 0;
}


int main(){
    InitializeCriticalSection(&cs);
    HANDLE t1 , t2;

    t1 = CreateThread(NULL , 0 ,  increment_function , NULL , 0 , NULL);
    t2 = CreateThread(NULL , 0 ,  increment_function , NULL , 0 , NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    printf("Final counter: %d\n", counter);
    DeleteCriticalSection(&cs);


    return 0;
}