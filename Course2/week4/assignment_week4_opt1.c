#include <stdio.h>
#include <stdlib.h>



void get_array_size(FILE *ifp, int *size)
{
    rewind(ifp);
    fscanf(ifp, "%d", size);
}

void populate_array(FILE *ifp, int data[], int size) {
    int num;
    rewind(ifp);
    for (int i=0; i<=size; i++){
        if (i==0)
            fscanf(ifp, "%d", &num); // discard the first integer into a dummy variable num.
        else
            fscanf(ifp, "%d", &data[i-1]);
    }
}



void print_array(int data[], int size)
{
    for (int i=0; i<size; i++){
        printf("%d\n", data[i]);
    }
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

    get_array_size(ifp, &size);
    int data[size];

    populate_array(ifp, data, size);
    print_array(data, size);

    return 0;
}

