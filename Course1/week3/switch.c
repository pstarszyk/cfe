# include <stdio.h>

int main(void)
{
    int i;
    printf("Enter a number\n");
    scanf("%d", &i);

    switch(i)
    {
        case 1: printf("case 1\n"); break;
        case 2: printf("case 2\n");
        case 3: printf("case 3\n"); break;
        default: printf("default\n"); break;
    }

    return 0;
}