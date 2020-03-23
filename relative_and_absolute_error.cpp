#include <iostream>
#include <cmath>
using namespace std;

double dfa(double a, double b, double c)
{
    return ((a * (a + pow(b, 2)) / (pow(a - b, 1. / 3) * (a + c))) + (((-a * (a + pow(b, 2))) / (3 * pow(a - b, 4. / 3))) + (2 * a + pow(b, 2)) / pow(a - b, 1. / 3)) * log(a + c));
}
double dfb(double a, double b, double c)
{
    return (a * (((2 * b) / (pow(a - b, 1. / 3))) + ((a + pow(b, 2)) / (3 * pow(a - b, 4. / 3)))) * log(a + c));
}
double dfc(double a, double b, double c)
{
    return (a * (a + pow(b, 2))) / (pow(a - b, 1. / 3) * (a + c));
}
double f(double a, double b, double c)
{
    return (a + pow(b, 2)) / (pow(a - b, 1. / 3)) * a * log(a + c);
}

int main()
{
    //points
    double a1 = 0.1245;
    double b1 = 0.12;
    double c1 = 2.08;

    //accuracy//
    double abs_a = 0.0005;
    double abs_b = 0.0003;
    double abs_c = 0.015;

    double otn_a = abs_a / a1;
    double otn_b = abs_b / b1;
    double otn_c = abs_c / c1;

    double f1 = f(a1, b1, c1);
    cout << "value at point f: (" << a1 << " , " << b1 << " , " << c1 << " ) = " << f1 << endl;

    double u_a = dfa(a1, b1, c1);
    double u_b = dfa(a1, b1, c1);
    double u_c = dfa(a1, b1, c1);

    double ABS = abs(u_a) * abs_a + abs(u_b) * abs_b + abs(u_c) * abs_c;
    cout << "Absolute error f = " << ABS << endl;

    double OTN = ABS / abs(f1);
    cout << "Relative error f = " << OTN << endl;

}
