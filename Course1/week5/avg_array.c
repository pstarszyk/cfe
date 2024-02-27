#include <stdio.h>

int main(void)
{
    const int SIZE = 5;
    int data[] = {3,1,6,2,9};
    int i;
    double sum = 0.0;
    double *p = &sum;

    for (i=0; i<SIZE; i++)
    {
        sum += data[i];
    }
    printf("Sum = %lf \n", sum);
    printf("Sum address is %p and value is %lf \n", p, *p);
    
    return 0;

}