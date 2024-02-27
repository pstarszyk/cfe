#include <stdio.h>
/*
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
    printf("Inside swap: i=%d, j=%d\n", *i, *j);
}

int main(void)
{
    int i=1, j=2;
    swap(&i, &j);
    printf("Inside main: i=%d, j=%d\n", i, j);
    return 0;
}
*/

void swap(int i, int j)
{
    int temp = i;
    i = j;
    j = temp;
    printf("Inside swap: i=%d, j=%d\n", i, j);
}

int main(void)
{
    int i=1, j=2;
    swap(i, j);
    printf("Inside main: i=%d, j=%d\n", i, j);
    return 0;
}