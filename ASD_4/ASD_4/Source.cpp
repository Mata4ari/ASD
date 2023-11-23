#include <iostream>
using namespace std;

void main()
{
	const int n = 5000;
	int A[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() %100+1;

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl << endl;

	int max = 0, min = 0, sum = 0;
	max = min = A[0];
	int imin=0, imax=0;

	if (n % 2 == 0)
	{
		for (int i = 0; i < n; i += 2)
		{
			max = min = A[i];
			imin = imax = i;
			for (int k = i; k < n; k++)
			{
				if (A[k] > max)
				{
					max = A[k];
					imax = k;
				}
				if (A[k] < min)
				{
					min = A[k];
					imin = k;
				}
			}
			swap(A[i], A[imax]);
			swap(A[i + 1], A[imin]);
			max = min = imin = imax = 0;
		}
	}
	else
	{
		for (int i = 0; i < n-1; i += 2)
		{
			max = min = A[i];
			imin = imax = i;
			for (int k = i; k < n; k++)
			{
				if (A[k] > max)
				{
					max = A[k];
					imax = k;
				}
				if (A[k] < min)
				{
					min = A[k];
					imin = k;
				}
			}
			swap(A[i], A[imax]);
			swap(A[i + 1], A[imin]);
			max = min = imin = imax = 0;
		}
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl << endl;

	for (int i = 0; i < n; i += 2)
		sum += A[i];
	cout << sum;

}