#include <iostream>
#include <math.h>
using namespace std;

const double goldenRatio = (1 + sqrt(5)) / 2;


double foo(double x)
{
	return (2 * (x * x)) + (3 * exp(-x));
}

int main() {
	double a, b;
	double accuracy = 0.001;
	double x1, x2;
	cin >> a >> b;
	while (fabs(b - a) > accuracy) {
		x1 = b - (b - a) / goldenRatio;
		x2 = a + (b - a) / goldenRatio;
		if (foo(x1) <= foo(x2))
			a = x1;
		else
			b = x2;
	}
	cout << "(" << (a + b) / 2 << ", " << foo((a + b) / 2) << ")";
	return 0;
}