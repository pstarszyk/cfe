#include <iostream>
using namespace :: std;

// this module shows necessary overloading for our custom data ype "point".
// there are operators (ie. _, -, <<, ... etc) in the standard library that work 
// out of the box on primitive/native data types (int, char, double, long, etc).
// But when you create your own custom type, these operators don't know how to 
// operate on them, therefore you need to override them, so that when you invoke
// those operators on your type, the necessary logic that you defined
// will be called underneath.

class point{
    public:
        point(){this -> x = 0.0; this -> y = 0.0;}
        double getx(){return x;}
        double gety(){return y;}
        void setx(double v){x = v;}
        void sety(double v){y = v;}
        double x, y;
};

point operator+ (point& p1, point& p2){
    point sum;
    sum.x = p1.x + p2.x;
    sum.y = p1.y + p2.y;
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main(void)
{
    point a, b, c;

    a.x = 1.1;
    a.y = 2.2;
    b.x = 3.3;
    b.y = 4.4;

    cout << "a = " << a << "b = " << b << endl;
    cout << "sum = " << a + b << endl;
    return 0;
}


