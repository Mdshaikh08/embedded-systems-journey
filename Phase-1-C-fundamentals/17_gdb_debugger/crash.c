#include <stdio.h>

void crash_me(int *ptr) {
    *ptr = 42;  // will crash if ptr is NULL
}

int main() {
    int *p = NULL;
    printf("About to crash...\n");
    crash_me(p);
    printf("This never prints\n");
    return 0;
}