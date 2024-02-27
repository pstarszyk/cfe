#include <stdio.h>

void recurse(int n)
{
    if (n == 0)
        {printf("hello\n");}
    else
        {printf("hello\n");
        recurse(n-1);
        printf("goodbye\n");}

}

int main(void)
{
    int n = 3;
    recurse(n);
    return 0;
}
