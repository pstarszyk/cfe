#include <stdio.h>

struct point{
    double x;
    double y;
} p1={4,p1.x};

int main(void){
    struct point *p = &p1;
    printf("%f\n", p->y);
    return 0;
}