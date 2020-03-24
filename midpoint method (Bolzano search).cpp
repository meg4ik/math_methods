#include <iostream>
#include <math.h>
using namespace std;


double f(double x)
{
	return (2 * (x * x)) + (3 * exp(-x));
}
double f1(double x)
{
	return (4 * x) - (3 * exp(-x));
}


int main() {
	cout << "midpoint method (Bolzano search)" << endl;
	double a = -1;
	double b = 1;
	double e = 0.001;
	double z = 0;
	z = b - f1(b) / ((f1(b) - f1(a)) / (b - a));
	while (abs(f1(z)) > e) {
		if (f1(z) < 0) {
			a = z;
		}
		else {
			b = z;
		}
		z = b - f1(b) / ((f1(b) - f1(a)) / (b - a));
	}
	cout << z << endl;


	return 0;
}