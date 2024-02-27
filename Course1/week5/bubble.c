#include <stdio.h>

void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void print_array(int n, int data[])
{
    int i;

    for (i=0; i<n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void bubble(int n, int data[])
{
    int i, j;

    for (i=0; i<n; i++){
        for (j=n-1; i<j; j--){
            if (data[j] < data[j-1])
                swap(&data[j], &data[j-1]);
        }
    }
}


int main(void)
{
    int n = 8;
    int data[] = {3,0,7,3,9,1,1,2};
    bubble(n, data);
    print_array(n, data);
    return 0;
}