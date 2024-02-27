# include <stdio.h>
# include <math.h>

int main(void)
{
    double interval;
    int i;

    for (i = 0; i < 300; i++)
    {
        interval = i / 10.0;
        printf("sin(%lf) = %lf \t", interval, fabs(sin(interval))); // blah
    }

    printf("\n++++++++++\n");
    return 0;
}

