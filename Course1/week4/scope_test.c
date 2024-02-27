#include <stdio.h>

void other_func(int n)
{
    printf("Address of n inside other_func: %p\n", &n);
}

int main(void)
{
    int n;
    printf("Address of n inside main: %p\n", &n);
    other_func(n);
    return 0;
}