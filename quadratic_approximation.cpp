
#include <iostream>
#include <math.h>
#include <algorithm> 
using namespace std;

double foo(double x)
{
    return (2 * (x * x)) + (3 * exp(-x));
}

int main() {
    double dx = 1;
    double accuracy1 = 0.001;
    double x1 = -1, x2 = 0, x3 = 0;
    int iter = 0;
    double foomin = 0;
    double xmin = 0;
    double xaprox = 0;
    double a1 = 0;
    double a2 = 0;
    x2 = x1 + dx;
    if (foo(x1) > foo(x2)) {
        x3 = x1 + 2 * dx;
    }
    else if (foo(x1) <= foo(x2)) {
        x3 = x1 - dx;
    }
    while (1) {
        foomin = min(foo(x1), foo(x2));
        foomin = min(foomin, foo(x3));
        if (foomin == foo(x1)) {
            xmin = x1;
        }
        else if (foomin == foo(x2)) {
            xmin = x2;
        }
        else
        {
            xmin = x3;
        }

        a1 = (foo(x2) - foo(x1)) / (x2 - x1);
        a2 = (1/(x3-x2)) * (((foo(x3)-foo(x1))/(x3-x1))-((foo(x2)-foo(x1))/(x2-x1)));
        xaprox = ((x1 + x2) / 2) - (a1 / (2 * a2));
        if (((abs((foomin - foo(xaprox)) / foo(xaprox))) < accuracy1)  && ((abs((xmin - xaprox) / xaprox)) < accuracy1)) {
            break;
        }
        else {
            x2 = xaprox;
            x3 = xmin;
        } }
    
cout <<" " << xaprox << " "<<foo(xaprox)<<endl;

    return 0;
}