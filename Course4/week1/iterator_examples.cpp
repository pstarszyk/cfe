#include <iostream>
#include <vector>
using namespace :: std;


int main(void)
{
    vector<int> vec = {1,2,3,4,5};

    for (vector<int>::iterator p = vec.begin(); p != vec.end(); p++){
        cout << *p;
    }
    cout << endl;

    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it;
    }
    cout << endl;

    return 0;
}

