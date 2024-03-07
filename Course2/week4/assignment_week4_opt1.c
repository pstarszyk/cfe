#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void get_array_size(FILE *ifp, int *size)
{
    // computes array size from the first value.
    rewind(ifp);
    fscanf(ifp, "%d", size);
}

void populate_array(FILE *ifp, int data[], int size) 
{
    // populates an array with the array size.
    int num;
    rewind(ifp);
    for (int i=0; i<=size; i++){
        if (i==0)
            fscanf(ifp, "%d", &num); // discard the first integer into a dummy variable num.
        else
            fscanf(ifp, "%d", &data[i-1]);
    }
}

void output_max(int data[], int size, int *max, FILE *ofp)
{
    // computes max.
    for (int i=0; i<size; i++){
        if (data[i] > *max)
            *max = data[i];
    }

    // outputs max to stdout and ofp.
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Max of data: %d\n", *max);
    for (int i=0; buffer[i] != '\0'; i++){
        putc(buffer[i], stdout);
        putc(buffer[i], ofp);
    }
    putc('\n', stdout);
    putc('\n', ofp);
}

void output_mean(int data[], int size, double *mean, FILE *ofp)
{
    // computes mean.
    for (int i=0; i<size; i++){
        *mean += (data[i] - *mean) / (i + 1); // rolling mean
    }

    // outputs mean to stdout and ofp.
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Mean of data: %lf\n", *mean);
    for (int i=0; buffer[i] != '\0'; i++){
        putc(buffer[i], stdout);
        putc(buffer[i], ofp);
    }
    putc('\n', stdout);
    putc('\n', ofp);
}

int main(int argc, char *argv[])
{
    if (argc != 3){
        printf("Need executable inputfile.\n\n");
        exit(1);
    }

    FILE *ifp = fopen(argv[1], "r+");
    FILE *ofp = fopen(argv[2], "w+");
    int size;
    int max = INT_MIN; // minimum value of C integer, from limits.h
    double mean = 0.0;

    get_array_size(ifp, &size);
    int data[size];

    populate_array(ifp, data, size);
    output_max(data, size, &max, ofp);
    output_mean(data, size, &mean, ofp);

    fclose(ifp);
    fclose(ofp);

    return 0;
}

