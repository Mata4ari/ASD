#include <iostream>
using namespace std;

void main()
{
	const int n = 20;
	int A[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % 12 + 1;


	int max = 0, sum = 0,res=0;

	for (int i = 0; i < n; i++)
	{
		for (int k = i; k < n; k++)
		{
			if (A[k] > A[i])
				swap(A[k], A[i]);
		}
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl << endl;

	int x = 0;
	max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (x == 2)
			break;
		sum++;
		if (max > A[i])
		{
			max = A[i];
			x++;
		}
	}
	cout << sum;
}