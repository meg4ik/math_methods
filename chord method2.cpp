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


int main()
{
	cout << "Chord Method" << endl;
	cout << "\n#1." << endl;
	double a = -1, b = 1;


	if (fu1_der1(a) * fu1_der2(a) > 0)
	{
		swap(a, b);
	}
	int k = 1;
	while (fabs(b - a) > 0.01)
	{
		a = b - (b - a) * fu1_no_der(b) / (fu1_no_der(b) - fu1_no_der(a));
		b = a - (a - b) * fu1_no_der(a) / (fu1_no_der(a) - fu1_no_der(b));
		cout << k << ". x = " << b << endl;
		k++;
	}
	cout << "x = " << b << endl;
	return 0;
}
