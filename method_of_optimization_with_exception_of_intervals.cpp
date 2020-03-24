#include <iostream>
#include <cmath>
using namespace std;
double foo(double x)
{
    return (2 * (x * x)) + (3 * exp(-x));
}

int main()
{
    double a, b, L, xm;
    cin >> a >> b;
    L = b - a;
    xm = (b + a) / 2.;
    double x1, x2;
    while (L > 0.001) {
        x1 = a + L / 4.;
        x2 = b - a / 4.;
        if (foo(x1) < foo(xm)) {
            b = xm;
            xm = x1;
        }
        else if(foo(xm)<foo(x2)) {
            a = x1;
            b = x2;
        }
        else {
            a = xm;
            xm = x2;
        }
            L = b - a;  
    }
    cout << L << "\n" << xm << "\n" << foo(xm);
}
