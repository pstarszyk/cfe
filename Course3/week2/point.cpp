#include <iostream>
using namespace :: std;

// this module shows necessary overloading for our custom data type "point".
// there are operators (ie. +, -, <<, ... etc) in the standard library that work 
// out of the box on primitive/native data types (int, char, double, long, etc).
// But when you create your own custom type, these operators don't know how to 
// operate on them, therefore you need to override them, so that when you invoke
// those operators on your type, the necessary logic that you defined
// will be called underneath.

class point{
    public:
        point(double x=0.0, double y=0.0): x(x), y(y){}
        double getx(){return x;}
        double gety(){return y;}
        void setx(double v){x = v;}
        void sety(double v){y = v;}
        double x, y;
};

point operator+ (point& p1, point& p2){
    point sum(p1.x + p2.x, p1.y + p2.y); // OR point sum = {p1.x + p2.x, p1.y + p2.y}; 
    // defining sum = (. + ., . + .) would discard the first result and just keep the second.
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main(void)
{
    point a=point(1.1, 2.2), b=point(3.3, 4.4), c;

    cout << "a = " << a << "b = " << b << endl;
    cout << "sum = " << a + b << endl;
    return 0;
}


