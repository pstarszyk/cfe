#include <iostream>
using namespace :: std;

template <class T1, class T2>
void copy_values(const T1 source[], T2 destination[], int size)
{
    for (int i=0; i<size; i++){
        destination[i] = static_cast<T2>(source[i]);
    }
}

int main(void)
{
    int size = 5;
    int source[] = {1,2,3,4,5};
    int* destination = new int[size];

    copy_values(source, destination, size);
    return 0;
}