#include <stdio.h>
#include <stdlib.h>


int main(void){
    FILE *file = fopen("elephant_seal_data.txt", "r");
    int n;

    n = fscanf(file, "%d", &n);
    printf("%d\n", n);
}