#include <stdio.h>

long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(void)
{
    int n;
    printf("Enter n.\n");
    scanf("%d", &n);
    printf("%ld\n", factorial(n));
    return 0;
}
