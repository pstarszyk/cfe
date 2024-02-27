#include <stdio.h>

long fibonacci_for(int n)
{
    int i;
    long n_1=1, n_2=0, cur;
    for (i = 2; i <= n; i++)
    {
        cur = n_1 + n_2;
        n_2 = n_1;
        n_1 = cur;
    }
    return cur;
}

long fibonacci_rec(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

int main(void)
{
    int n;
    printf("Enter n.\n");
    scanf("%d", &n);
    printf("%ld\n", fibonacci_rec(n));
    return 0;
}