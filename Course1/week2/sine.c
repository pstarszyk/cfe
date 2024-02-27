#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    double sine;
    printf("Enter a value\n");
    scanf("%lf", &x);
    sine = sin(x);
    printf("The answer is %lf\n", sine);
    return 0;
}