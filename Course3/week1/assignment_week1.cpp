// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function 

#include <iostream> // change to C++ io.
#include <vector> // include C++ vector.
using namespace :: std; // need namespac efor cout.
const int N = 40; // change defines of constants to const.

inline void sum(int *p, int n, vector<int>& d) // inline short function.
{
    int i;
    *p = 0;
    for(i = 0; i < n; ++i)
        *p = *p + d[i];
}

int main(void)
{
    int accum = 0;
    vector<int> data(N); // define data as C++ vector.

    for(int i = 0; i < N; ++i) // localize iterator i.
        data[i] = i;
    sum(&accum, N, data);
    cout << "sum is " << accum << "\n"; // change printf -> cout.
    return 0;
}