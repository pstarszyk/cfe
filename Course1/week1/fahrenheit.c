#include <stdio.h>

int main(void)
{

    double C, F;
    // C = (F - 32) / 1.8
    printf("Enter degrees Fahrenheit:\n");
    scanf("%lf", &F);
    C = (F - 32) / 1.8;
    printf("%lf degrees F = %lf degrees C.\n", F, C);
    return 0;
}