# include <stdio.h>

int main(void)
{
    printf("float is %lu bytes.\n", sizeof(float));
    printf("int is %lu bytes.\n", sizeof(int));
    printf("char is %lu bytes.\n", sizeof(char));
    printf("double is %lu bytes.\n", sizeof(double));
    printf("long double is %lu bytes.\n", sizeof(long double));
    printf("long int is %lu bytes.\n", sizeof(long int));
    return 0;
}