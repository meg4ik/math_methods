#include <iostream>
#include <cmath>
using namespace std;

double dfa(double a, double b, double c)
{
    return ((1. / pow(a - b, 1. / 2)) - ((a + b) / (2 * pow(a - b, 3. / 2)))) * log(a * c) + 1 + ((a + b) / (a * pow(a - b, 1. / 2)));
}
double dfb(double a, double b, double c)
{
    return ((1 / pow(a - b, 1. / 2)) + ((a + b) / (2 * pow(a - b, 3. / 2)))) * log(a * c);
}
double dfc(double a, double b, double c)
{
    return (a + b) / (c * pow(a - b, 1. / 2));
}
double f(double a, double b, double c)
{
    return a + (a + b) / (pow(a - b, 1. / 2)) * log10(a * c);
}

int main()
{
    //points
    double a1 = 0.02456;
    double b1 = 0.01823;
    double c1 = 3.0148;
    
    double fa = f(a1, b1, c1);

    double ABSf = 4.0000e-004;
    
    double u_a = abs(dfa(a1, b1, c1));
    double u_b = abs(dfb(a1, b1, c1));
    double u_c = abs(dfc(a1, b1, c1));

    double rA = ABSf / abs(u_a * 3);
    double rB = ABSf / abs(u_b * 3);
    double rC = ABSf / abs(u_c * 3);

    cout << "U(a) = " << rA << endl;
    cout << "U(a) = " << rB << endl;
    cout << "U(a) = " << rC << endl;

    double t = ABSf / (u_a + u_b + u_c);

    cout << "U(F) = " << t << endl;
    
}