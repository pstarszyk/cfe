#include <stdio.h>

int main(void)
{
    int i, n, sum = 0;
    printf("Enter a number\n");
    scanf("%d", &n);

    for (i=1; i<=n; i++)
    {
        sum += i;
    }
    printf("Sum: %d\n", sum);
    return 0;
}