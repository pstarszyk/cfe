#include <stdio.h>

#define SIZE 100

void read_data(FILE *ptr, int data[], int *size){
    *size = 0;
    while(fscanf(ptr, "%d", &data[*size]) != EOF){
        (*size)++;
    }
}


void print_data(int data[], int size){
    printf("Data:\n");
    for (int i=0; i<size; i++){
        printf("%d\n", data[i]);
    }
}

void print_average(int data[], int size){
    double sum=0;
    for (int i=0; i<size; i++){
        sum += data[i];
    }
    printf("Average:\n");
    printf("%lf\n", sum/size);
}

int main(void){
    int i, sz = SIZE;
    FILE *fp;
    int data[SIZE];

    fp = fopen("data.txt", "r");
    read_data(fp, data, &sz);
    print_data(data, sz);
    print_average(data, sz);
    
    fclose(fp);

    return 0;
}
