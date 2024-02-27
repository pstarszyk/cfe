#include <stdio.h>
#include <stdlib.h>

#define MIN_WEIGHT 4000
#define MAX_WEIGHT 8000
#define RANGE 4000
#define POPULATION 1000
#define WEIGHT_OVER rand() % RANGE
#define WEIGHT MIN_WEIGHT + WEIGHT_OVER
#define FILL for (i=0; i<POPULATION; i++){data[i] = WEIGHT;} 

void print_data(int data[], int size){
    int i;
    for (i=0; i<size; i++){
        printf("%d\t", data[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}


int main(void){
    int i;
    int data[POPULATION];
    FILL;
    print_data(data, POPULATION);
    return 0;
}
