#include <stdio.h>

int main(void)
{
    int miles, yards;
    double kilometers;

    printf("\nEnter miles.\n");
    scanf("%d", &miles);
    printf("\nEnter yards.\n");
    scanf("%d", &yards);
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\n%d miles %d and yards = %lf kilometers.\n\n", miles, yards, kilometers);
    return 0;
}