#include <stdio.h>
#define pi 3.14159

int main()
{
    double area = 0, radius = 0;
    printf("Enter Radius: ");
    scanf("%lf", &radius);
    area = pi * radius * radius;
    printf("Area = %lf\n", area);
    return 0;
}