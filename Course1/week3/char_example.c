# include <stdio.h>

int main(void)
{
    int blanks = 0, digits = 0, total_chars = 0;
    int c;
    for(; (c = getchar()) != EOF; total_chars++ )
    {
        if (c ==  ' ')
            ++blanks;
        else if (c >= '0' && c <= '9')
            ++digits;
        c++;
    };
    printf("blanks = %d, digits = %d, total_chars = %d\n\n",
    blanks, digits, total_chars);
    return 0;
}