/*
#include <stdio.h>

void foo(int *ptr) {
    printf("Address held by ptr: %p\n", (void*)ptr);
    printf("Value at that address: %d\n", *ptr);
    
    // Modify the value at the address ptr points to
    *ptr = 20;
}

int main() {
    int x = 10;
    printf("Original value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);

    foo(&x); // Pass the address of x to foo

    printf("New value of x after foo: %d\n", x); // x has been modified by foo
    return 0;
}
*/

#include <stdio.h>

void foo(int *ptr) {
    printf("Address held by ptr: %p\n", (void*)ptr);
    printf("Value at that address: %d\n", *ptr);
    
    // Modify the value at the address ptr points to
    *ptr = 20;
}

int main() {
    int value = 0; 
    int *x = &value; // need to initilaize pointer first before dereferencing it
    *x = 10;
    printf("Original value of x: %d\n", *x);
    printf("Address of x: %p\n", x);

    foo(x); // Pass the address of x to foo

    printf("New value of x after foo: %d\n", *x); // x has been modified by foo
    return 0;
}