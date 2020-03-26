#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm> 
#include <ctime>
using namespace std;

const double goldenRatio = (1 + sqrt(5)) / 2;

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

double golden_ratio_method() {
	unsigned int start_time = clock();
	double a = -1;
	double b = 1;
	double accuracy = 0.01;
	double x1, x2;
	int iter = 0;
	while (fabs(b - a) > accuracy) {
		iter++;
		x1 = b - (b - a) / goldenRatio;
		x2 = a + (b - a) / goldenRatio;
		if (fu1_no_der(x1) >= fu1_no_der(x2))
			a = x1;
		else
			b = x2;
	}
	unsigned int end_time = clock();
	cout << "golden ratio method " << "x = " << (a + b) / 2 << " iterations: " << iter << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;
	return 0;
}

double dilenna_napopolam_method() {
	unsigned int start_time = clock();
	double a, b, L, xm;
	a = -1;
	b = 1;
	L = b - a;
	xm = (b + a) / 2.;
	double x1, x2;
	int iter = 0;
	while (L > 0.001) {
		iter ++;
		x1 = a + L / 4.;
		x2 = b - L / 4.;
		if (fu1_no_der(x1) < fu1_no_der(xm)) {
			b = xm;
			xm = x1;
		}
		else if (fu1_no_der(xm) < fu1_no_der(x2)) {
			a = x1;
			b = x2;
		}
		else {
			a = xm;
			xm = x2;
		}
		L = b - a;
	}
	unsigned int end_time = clock();
	cout << "dilenna napopolam method " << "x = " << xm << " iterations: " << iter << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;
	return 0;
}

double sekuchix() {
	unsigned int start_time = clock();
	double a = -1;
	double b = 1;
	double e = 0.001;
	double z = 0;
	z = (a + b) / 2;
	int k = 0;
	while (abs(fu1_der1(z)) > e) {
		k++;
		if (fu1_der1(z) < 0) {
			a = z;
		}
		else {
			b = z;
		}
		z = (a + b) / 2;
	}
	unsigned int end_time = clock();
	cout << "sekuchix metod " << "x = " << z << " iterations: " << k << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;
	return 0;
}

double Newton_Raphson_Method() {
	unsigned int start_time = clock();
	double a = -1, b = 1, x = 0.001;
	int k = 0;
	for (;;) {
		k++;
		a = a - (fu1_der1(a) / fu1_der2(a));
		if (abs(fu1_der1(a))<x) { break; }
	}
	unsigned int end_time = clock();
	cout << "Newton Raphson Method " << "x = " << a << " iterations: " << k << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;
	return 0;
}

double  midpoint_method() {
	unsigned int start_time = clock();
	double a = -1;
	double b = 1;
	double e = 0.001;
	double z = 0;
	z = b - fu1_der1(b) / ((fu1_der1(b) - fu1_der1(a)) / (b - a));
	int k = 0;
	while (abs(fu1_der1(z)) > e) {
		k++;
		if (fu1_der1(z) < 0) {
			a = z;
		}
		else {
			b = z;
		}
		z = b - fu1_der1(b) / ((fu1_der1(b) - fu1_der1(a)) / (b - a));
	}
	unsigned int end_time = clock();
	cout << "midpoint method (Bolzano search) " << "x = " << z << " iterations: " << k << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;


	return 0;
}

double kubicj_aprox() {
	unsigned int start_time = clock();
	double x[100];
	x[0] = -1;
	double d1 = 1, e1 = 0.01, e2 = 0.01;
	double x_1, x_2;
	double Mmax = 0;
	double Mma = 0;
	int k = 0;
	int iter =0;
	if (fu1_der1(x[0]) < 0)
	{
		for (;;) {
			x[k + 1] = x[k] + pow(2, k) * d1;
			Mmax = x[k + 1];
			Mma = x[k];
			if ((fu1_der1(Mma) * fu1_der1(Mmax)) <= 0) { break; }
			k++;
		}

	}
	else {
		for (;;) {
			x[k + 1] = x[k] - pow(2, k) * d1;
			Mmax = x[k + 1];
			Mma = x[k];
			if ((fu1_der1(Mma) * fu1_der1(Mmax)) <= 0) { break; }
			k++;
		}
	}
	x_1 = Mma;
	x_2 = Mmax;
	double z, w, u, x_super;
	for (;;) {
		iter++;
		z = ((3 * (fu1_no_der(x_1) - fu1_no_der(x_2))) / (x_2 - x_1)) + fu1_der1(x_1) + fu1_der1(x_2);
		if (x_1 < x_2) {
			w = pow((z * z) - fu1_der1(x_1) * fu1_der1(x_2), 0.5);
		}
		else {
			w = -1 * (pow((z * z) - fu1_der1(x_1) * fu1_der1(x_2), 0.5));
		}
		u = (fu1_der1(x_2) + w - z) / (fu1_der1(x_2) - fu1_der1(x_1) + 2 * w);
		if (u < 0) {
			x_super = x_2;
		}
		else if (u >= 0 && u <= 1) {
			x_super = x_2 - u * (x_2 - x_1);
		}
		else { x_super = x_1; }
		if (fu1_no_der(x_super) >= fu1_no_der(x_1)) {
			for (;;) {
				x_super = x_super - (x_super - x_1) / 2;
				if (fu1_no_der(x_super) <= fu1_no_der(x_1)) { break; }
			}
			break;
		}
		else {
			if (abs(fu1_der1(x_super)) >= e1 && abs(x_super - (x_1 / x_super)) >= e2) {
				if ((fu1_der1(x_super) * fu1_der1(x_1)) < 0) {
					x_1 = x_super;
					x_2 = x_1;
				}
				else if ((fu1_der1(x_super) * fu1_der1(x_2)) < 0) {
					x_1 = x_super;
					x_2 = x_2;
				}
			}
			else { break; }
		}
	}
	unsigned int end_time = clock();
	cout << "kubicj_aprox " << "x = " << x_super << " iterations: " << iter << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;
	return 0;
}

double quadratic_aproximation() {
	unsigned int start_time = clock();
	double dx = 1;
	double accuracy1 = 0.001;
	double x1 = -1, x2 = 0, x3 = 0;
	int iter = 0;
	double foomin = 0;
	double xmin = 0;
	double xaprox = 0;
	double a1 = 0;
	double a2 = 0;
	x2 = x1 + dx;
	if (fu1_no_der(x1) > fu1_no_der(x2)) {
		x3 = x1 + 2 * dx;
	}
	else if (fu1_no_der(x1) <= fu1_no_der(x2)) {
		x3 = x1 - dx;
	}
	while (1) {
		iter++;
		foomin = min(fu1_no_der(x1), fu1_no_der(x2));
		foomin = min(foomin, fu1_no_der(x3));
		if (foomin == fu1_no_der(x1)) {
			xmin = x1;
		}
		else if (foomin == fu1_no_der(x2)) {
			xmin = x2;
		}
		else
		{
			xmin = x3;
		}

		a1 = (fu1_no_der(x2) - fu1_no_der(x1)) / (x2 - x1);
		a2 = (1 / (x3 - x2)) * (((fu1_no_der(x3) - fu1_no_der(x1)) / (x3 - x1)) - ((fu1_no_der(x2) - fu1_no_der(x1)) / (x2 - x1)));
		xaprox = ((x1 + x2) / 2) - (a1 / (2 * a2));
		if (((abs((foomin - fu1_no_der(xaprox)) / fu1_no_der(xaprox))) < accuracy1) && ((abs((xmin - xaprox) / xaprox)) < accuracy1)) {
			break;
		}
		else {
			x2 = xaprox;
			x3 = xmin;
		}
	}
	unsigned int end_time = clock();
	cout << "quadratic_aproximation " << "x = " << xaprox << " iterations: " << iter << " time= " << ((end_time / 1000.0) - (start_time / 1000.0)) << endl;
	return 0;
}

int main() {
	dilenna_napopolam_method();
	golden_ratio_method();
	quadratic_aproximation();
	Newton_Raphson_Method();
	sekuchix();
	midpoint_method();
	kubicj_aprox();
	return 0;
}