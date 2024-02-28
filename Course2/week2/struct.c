#include <stdio.h>

struct my_struct{
    int mem1;
    char mem2;
};
struct my_struct c;

/*
int main(void){
    c.mem1=3;
    c.mem2='h';

    printf("%d\n", c.mem1);
    printf("%c\n", c.mem2);

    return 0;
}
*/

int main(void){
    struct my_struct *p = &c;
    p -> mem1 = 5;
    p -> mem2 = 's';

    printf("%d\n", p->mem1);
    printf("%c\n", p->mem2);

    return 0;
}