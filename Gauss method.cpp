#include <math.h>
#include <iostream>
using namespace std;

void glavelem(int k, double mas[][5 + 1], int n, int otv[])
{
	int i, j, i_max = k, j_max = k;
	double temp;

	for (i = k; i < n; i++)
		for (j = k; j < n; j++)
			if (fabs(mas[i_max][j_max]) < fabs(mas[i][j]))
			{
				i_max = i;
				j_max = j;
			}

	for (j = k; j < n + 1; j++)
	{
		temp = mas[k][j];
		mas[k][j] = mas[i_max][j];
		mas[i_max][j] = temp;
	}

	for (i = 0; i < n; i++)
	{
		temp = mas[i][k];
		mas[i][k] = mas[i][j_max];
		mas[i][j_max] = temp;
	}

	i = otv[k];
	otv[k] = otv[j_max];
	otv[j_max] = i;
}

int main()
{
	double mas[5][5 + 1];
	double x[5];
	int otv[5];
	int i, j, k, n;

	do
	{
		cout << "Enter the number of system equations(2-5) : ";
		cin >> n;
	} while (5 < n);
	cout << "Enter numbers:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
			cin >> mas[i][j];

	for (i = 0; i < n + 1; i++)
		otv[i] = i;


	for (k = 0; k < n; k++)
	{
		glavelem(k, mas, n, otv);

		for (j = n; j >= k; j--)
			mas[k][j] /= mas[k][k];
		for (i = k + 1; i < n; i++)
			for (j = n; j >= k; j--)
				mas[i][j] -= mas[k][j] * mas[i][k];
	}

	for (i = 0; i < n; i++)
		x[i] = mas[i][n];
	for (i = n - 2; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			x[i] -= x[j] * mas[i][j];


	cout << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == otv[j])
			{
				cout << x[j] << endl;
				break;
			}
	return 0;
}
