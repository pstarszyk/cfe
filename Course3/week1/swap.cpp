#include <iostream>
using namespace :: std;

inline void swap(double& i, double& j)
{
    double temp = i;
    i = j;
    j = temp;
}

inline void swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

int main(void)
{
    int i=1, j=2;
    cout << "i = " << i << ", j = " << j << endl;
    swap(i, j);
    cout << "i = " << i << ", j = " << j << endl;

    double ii=1.1, jj=2.2;
    cout << "ii = " << ii << ", jj = " << jj << endl;
    swap(ii, jj);
    cout << "ii = " << ii << ", jj = " << jj << endl;

    return 0;
}