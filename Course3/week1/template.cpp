#include <iostream>
using namespace :: std;

// template <class summable>
// // summable is the generic type
// summable sum(const summable data[], int size)
// {
//     summable s = 0;
//     for (int i=0; i<size; i++){
//         s += data[i];
//     }
//     return s;
// }

template <class T>
inline T sum(T data[], int size)
{
    T sm = 0;
    for (int i=0; i<size; i++){
        sm += data[i];
    }
    return sm;
}

int main(void)
{
    int size = 5;
    int data1[size] = {1, 2, 3, 4, 5};
    double data2[size] = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << "sum of data1 is " << sum(data1, size) << endl;
    cout << "sum of data2 is " << sum(data2, size) << endl;

    return 0;
}
