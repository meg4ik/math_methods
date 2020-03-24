#include <iostream>
#include <math.h>
using namespace std;

double f0(double x) {
	return (2 * (x * x)) + (3 * exp(-x));
}
double f1(double x) {
	return (4 * x) - (3 * exp(-x));
}


int main() {
	cout << "kubicj aprox" << endl;
	double x[100];
	//x[0] = 1;
	//double d1 = 1, e1 = 0.01, e2 = 0.03;
	x[0] = -1;
	double d1 = 1, e1 = 0.01, e2 = 0.03;
	double x_1, x_2;
	double Mmax = 0;
	double Mma = 0;
	int k = 0;
	if (f1(x[0]) < 0)
	{
		for (;;) {
			x[k + 1] = x[k] + pow(2, k) * d1;
			Mmax = x[k + 1];
			Mma = x[k];
			if ((f1(Mma) * f1(Mmax)) <= 0) { break; }
			k++;
		}

	}
	else {
		for (;;) {
			x[k + 1] = x[k] - pow(2, k) * d1;
			Mmax = x[k + 1];
			Mma = x[k];
			if ((f1(Mma) * f1(Mmax)) <= 0) { break; }
			k++;
		}
	}
	x_1 = Mma;
	x_2 = Mmax;
	double z, w, u, x_super;
	for (;;) {
		z = ((3 * (f0(x_1) - f0(x_2))) / (x_2 - x_1)) + f1(x_1) + f1(x_2);
		if (x_1 < x_2) {
			w = pow((z * z) - f1(x_1) * f1(x_2), 0.5);
		}
		else {
			w = -1 * (pow((z * z) - f1(x_1) * f1(x_2), 0.5));
		}
		u = (f1(x_2) + w - z) / (f1(x_2) - f1(x_1) + 2 * w);
		if (u < 0) {
			x_super = x_2;
		}
		else if (u >= 0 && u <= 1) {
			x_super = x_2 - u * (x_2 - x_1);
		}
		else { x_super = x_1; }
		if (f0(x_super) >= f0(x_1)) {
			for (;;) {
				x_super = x_super - (x_super - x_1) / 2;
				if (f0(x_super) <= f0(x_1)) { break; }
			}
			break;
		}
		else {
			if (abs(f1(x_super)) >= e1 && abs(x_super - (x_1 / x_super)) >= e2) {
				if ((f1(x_super) * f1(x_1)) < 0) {
					x_1 = x_super;
					x_2 = x_1;
				}
				else if ((f1(x_super) * f1(x_2)) < 0) {
					x_1 = x_super;
					x_2 = x_2;
				}
			}
			else { break; }
		}
	}

	cout << "answer  - - ->>> " << x_super << endl;
	return 0;
}