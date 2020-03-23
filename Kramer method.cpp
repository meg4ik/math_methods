#include <iostream>
#include <cmath>
using namespace std;

double det(int n, double A[4][4])
{
	if (n == 1) {
		return A[0][0];
	}
	else {
		double M1[4][4];
		double r = 0;
		int i, iterator, j, k;
		for (i = 0; i < n; i++) {
			for (k = 1; k < n; k++) {
				iterator = 0;
				for (j = 0; j < n; j++) {
					if (j != i)
						M1[k - 1][iterator++] = A[k][j];
				}
			}
			if (i % 2 == 0) {
				r += A[0][i] * det(n - 1, M1);
			}
			else {
				r -= A[0][i] * det(n - 1, M1);
			}
		}
		return r;
	}
}

int main() {
	double A[4][4];
	double mod[4];
	double buf[4];
	double B[4];

	cout << "Enter A-matrix: " << endl;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			cout << "A [" << i + 1 << " , " << j + 1 << "] =  ";
			cin >> A[i][j];
		}
	cout << endl;
	cout << "Enter B-matrix: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "B [" << i + 1 << "] = ";
		cin >> B[i];
	}
	double del = det(4, A);

	for (int i = 0; i < 4; i++)
	{
		buf[i] = A[i][0];
		A[i][0] = B[i];
	}
	mod[0] = det(4, A);

	for (int k = 0; k < 3; k++)
	{
		for (int j = 0; j < 4; j++)
			A[j][k] = buf[j];
		for (int i = 0; i < 4; i++)
		{
			buf[i] = A[i][k + 1];
			A[i][k + 1] = B[i];
		}
		mod[k + 1] = det(4, A);
	}

	cout << endl;
	for (int k = 0; k < 4; k++)
	{
		cout << "x" << (k + 1) << " = " << round(mod[k] / del * 1000) / 1000 << endl;
	}
	return 0;
}