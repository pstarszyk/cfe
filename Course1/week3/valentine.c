# include <stdio.h>

int main(void)
{
    int repeat;
    printf("How strong is your love 1-10?\n");
    scanf("%d", &repeat);

    printf("I love Jen\n");
    while (repeat > 0)
    {
        printf("very\n");
        repeat--;
    }
    printf("much\n");
    return 0;
}