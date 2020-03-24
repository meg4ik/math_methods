#include <iostream>
#define _USE_MATH_DEFINES
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
	cout << "sekuchix metod" << endl;
	double a = -1;
	double b= 1;
	double e= 0.01;
	double z = 0;
	z = (a + b) / 2;
	while (abs(f1(z)) > e) {
		if (f1(z) < 0) {
			a = z;
		}
		else {
			b = z;
		}
		z = (a + b) / 2;
	}
	cout << z << endl;
	

	return 0;
}