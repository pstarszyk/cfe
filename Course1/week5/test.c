#include <stdio.h>

int foo(int p, int q){
    int r;
    if ((r=p%q)==0)
        return q;
    else return foo(q,r);
}

int main(void){
    char a[5]="abcd";
    char* str=&a[0];
    printf("%c\n", *str);
    return 0;
}