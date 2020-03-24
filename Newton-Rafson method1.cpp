#include <iostream>
#include <math.h>
using namespace std;

double funct(double x)
{
    return (2 * pow(x,2)) + (3 * exp(-x));
}
double funct1(double x)
{
    return (4 * x) - (3 * exp(-x));
}
double funct2(double x)
{
    return 4 + (3 * exp(-x));
}

int main()
{
    cout << "Newton-Rafson method" << endl;
    double a = -1, b = 1, e = 0.001, x = 0;
    int iter = 0;

    if (funct(a) * funct2(a) > 0) x = a;
    else if (funct(b) * funct2(b) > 0) x = b;
    else return 0;

    while (true)
    {
        x = x - funct(x) / funct1(x);
        iter++;
        if (fabs(funct(x)) < e) break;
    }
    //not shoditsa
    cout << "x = " << x << endl;


    return 0;
}