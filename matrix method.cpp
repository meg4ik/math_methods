#include <iostream>
#include <cmath>
using namespace std;

double det(double** A, int n)
{
	if (n == 1) {
		return A[0][0];
	}
	else {
		double** M1 = new double* [4];
		for (int i = 0; i < 4; i++)
			M1[i] = new double[4];

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
				r += A[0][i] * det(M1, n - 1);
			}
			else {
				r -= A[0][i] * det(M1, n - 1);
			}
		}
		for (int i = 0; i < 4; i++)
			delete[] M1[i];
		delete[] M1;

		return r;
	}
}

int main()
{
	double** A = new double* [4];
	for (int i = 0; i < 4; i++)
		A[i] = new double[4];

	double B[4];
	double det1;

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

	det1 = det(A, 4);
	int n = 4;
	int k, k1;


	for (int index1 = 0; index1 < n; index1++)
		for (int index2 = 0; index2 < n; index2++)
		{
			k = index1; k1 = index2;
			double** temp = new double* [n - 1];
			for (int i = 0; i < n - 1; i++)
				temp[i] = new double[n - 1];
			int s = 0, s1 = 0;
			for (int i = 0; i < n; ++i)
				if (i != k)
				{
					s1 = 0;
					for (int j = 0; j < n; ++j)
						if (j != k1)
						{
							temp[s][s1] = A[i][j];
							s1++;
						}

					s++;
				}
			cout << "\nminor of A" << k + 1 << k1 + 1 << endl;
			for (int i = 0; i < n - 1; ++i)
			{
				for (int j = 0; j < n - 1; ++j)
				{

					cout << temp[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			A[index1][index2] = det(temp, 3);
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			A[i][j] = A[i][j] * B[j];
	for (int i = 0; i < 4; i++)
		B[i] = A[i][0] + A[i][1] + A[i][2] + A[i][3];

	for (int i = 0; i < 4; i++)
		B[i] = B[i] * (1.0 / det1);

	for (int i = 0; i < 4; i++)
		cout << "x" << i << " = " << B[i] << endl;
	return 0;
}
