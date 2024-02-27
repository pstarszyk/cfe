#include <stdio.h>

double average(int n, int data[])
{
    int i;
    double avg = 0;

    for (i=0; i<n; i++)
    {
        avg += (data[i] - avg)/(i+1);
    }
    return avg;
}

int main(void)
{
    int data[] = {1,2,3,4,5};
    printf("%lf\n", average(5, data));
    return 0;
}