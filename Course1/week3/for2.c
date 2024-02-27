#include <stdio.h>

int main(void)
{
    int i, n, sum;
    float average;
    printf("Enter a number\n");
    scanf("%d", &n);

    for (sum=0, average=0, i=1; i<=n; i++)
    {
        sum += i;
        average += (i - average) / i;
    }
    printf("Sum: %d\n", sum);
    printf("Average: %lf\n", average);
    return 0;
}