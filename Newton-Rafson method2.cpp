#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

double fu1_no_der(double x)
{
	return (2 * (x * x)) + (3 * exp(-x));
}
double fu1_der1(double x)
{
	return (4 * x) - (3 * exp(-x));
}
double fu1_der2(double x)
{
	return 4 + (3 * exp(-x));
}


int main() {
	cout << "Newton Raphson Method" << endl;
	cout << "\n#1." << endl;
	double a = -1, b = 1, x = 0.01;
	if (fu1_der1(a) * fu1_der2(a) < 0) {
		x = a;
	}
	else if (fu1_der2(b) * fu1_der2(b) > 0) {
		x = b;
	}
	else {
		cout << "sxodimist ne vipolnena" << endl;
		return 0;
	}
	int k = 1;
	while (fabs(fu1_no_der(x)) > 0.01) {
		x = x - fu1_no_der(x) / fu1_der1(x);
		cout << k << ". x = " << x << endl;
		k++;
	}
	cout << "x = " << x << endl;
	return 0;
}