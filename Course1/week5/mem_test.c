#include <stdio.h>

// test if int passed to foo() has same address as in main


void foo(int data)
{
    printf("address in foo: %p\n", &data);
}

int main(void)
{
    int n=5;
    int data=6;
    printf("address in main: %p\n", &data);
    foo(data);
}



// test if array passed to foo() has same address as in main
/*
void foo(int data[])
{
    printf("address in foo: %p\n", &data[0]);
}

int main(void)
{
    int n=5;
    int data[]={1,2,3,4};
    printf("address in main: %p\n", &data[0]);
    foo(data);
}
*/