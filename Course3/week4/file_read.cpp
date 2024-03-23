#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace :: std;

int main(void)
{
    ifstream word_file("word.txt");
    istream_iterator<string> start(word_file), end;
    vector<string> words(start, end);

    cout << "\n\nWords of file:\n\n";
    for (auto str: words){
        cout << str << "\t";
    }
    cout << endl;

    return 0;
}

