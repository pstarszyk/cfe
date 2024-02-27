#include <stdio.h>

int main(void)
{
    const int SIZE = 5;
    int data[] = {3,1,6,2,9};
    int *p = &data;

    printf("data is stored from address %lu to %lu\n", data, data+SIZE);
    
    return 0;
}