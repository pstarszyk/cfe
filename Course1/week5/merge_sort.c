#include <stdio.h>


void merge(int a[], int b[], int c[], int m, int n)
{
    int i=0, j=0, k=0;
    while (i < m && j < n){
        if (a[i] < b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    while (i < m){
        c[k++] = a[i++];
    }
    while (j < n){
        c[k++] = b[j++];
    }    
}

void print_array(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
}

int main(void)
{
    const int m=3, n=3;
    int a[3] = {1, 4, 7};
    int b[3] = {2, 3, 8};
    int c[m+n];
    merge(a, b, c, m, n);
    print_array(c, m + n);
    return 0;
}