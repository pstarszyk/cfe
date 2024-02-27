#include <stdio.h>
#include <stdlib.h>

/*
int main(void)
{
    int i; // index of weight
    double average = 0; // average weight initialized as 0
    int current; // weight of current seal
    FILE *file = fopen("elephant_seal_data.txt", "r");

    // while loop iterates through file until EOF is reached    
    while (fscanf(file, "%d", &current) != EOF){
        average += (current - average) / (i + 1); // update rolling average
        i++;
    }

    fclose(file);

    printf("The average weight is %lf.\n\n", average);
    return 0;
}
*/

int main(void)
{
    int i; // index of weight
    double average = 0; // average weight initialized as 0
    int current; // weight of current seal
    int numbers[];
    FILE *file = fopen("elephant_seal_data.txt", "r");

    // while loop iterates through file until EOF is reached    
    while (fscanf(file, "%d", &current) != EOF){
        numbers[i] = current;
        i++;
    }

    fclose(file);

    printf("The average weight is %lf.\n\n", average);
    return 0;
}
