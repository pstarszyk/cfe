#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace :: std;


int main(void)
{
    map<unsigned long, string> worker;
    unordered_map<unsigned long, unsigned> payroll;
    worker[123] = "me";
    worker[456] = "you";
    payroll[123] = 1000;
    payroll[456] = 2000;
    unsigned total_pay = 0;

    for (auto p = worker.begin(); p != worker.end(); p++){
    // for (map<unsigned long, string>::iterator p = worker.begin(); p != worker.end(); p++){ <---- alternative to auto, specify container type
        cout << "name " << (*p).second << "\tID# " << (*p).first << endl;
    }

    for (auto p = payroll.begin(); p != payroll.end(); p++){
        total_pay += (*p).second;
        // total_pay += p -> second; <---- alternative, have pointer to second
    }

    cout << "total pay: " << total_pay << endl;

    return 0;
}

