#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void* handle_thread(int arg) {
    printf("Hello %d", arg);
    return 0;
}   

// foo accepts a function ptr so what what we need to pass in is a memory address 
// of a subroutine i.e handle_thread.
// Once we have the mem addr then that subroutine should have the same exact types
int foo(void* (*subroutine)(int arg)) {
    subroutine(0);
    return 0;
}

int main(int argc, char* argv[]) {

    foo(&handle_thread);
    return 0;
}