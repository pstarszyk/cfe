#include <stdio.h>

void write_very(int n)
{
    while (n > 0)
    {
        printf("very\n");
        n -= 1;
    }
}

int main(void)
{
    int n;
    printf("Input n.\n");
    scanf("%d", &n);
    printf("I love Naomi\n");
    write_very(n);
    printf("much.\n");
    return 0;
}