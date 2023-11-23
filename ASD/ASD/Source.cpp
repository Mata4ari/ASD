#include <iostream>
#include <time.h> 
using namespace std;
int fib(int n);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int x,n;
	long a = 0, a1 = 1, temp = 0;
	cout << "1 - ����, 2 - ��������" << endl;
	cin >> x;
	if (x!=1&&x!=2)
	{
		cout << "������";
		return (0);
	}
	cout << "������� ����� ����� ���������" << endl;
	cin >> n;
	if (x == 1)
	{
		clock_t start{ clock() };
		for (int i = 0; i < n-2; i++)
		{
			temp = a+a1;
			a = a1;
			a1 = temp;
		}
		cout << "N ����� =" << temp << endl;
		clock_t end{ clock() };
		int time{ (end - start) / CLOCKS_PER_SEC };

		cout << "��������� ����� ������ " << (int)time / 60 << " ����� " << time << " ������";
	}
	else if (x == 2)
	{
		clock_t start{ clock() };
		int i = 0;
		cout << "N ����� =" << fib(n) << endl;
		clock_t end{ clock() };
		int time{ (end - start) / CLOCKS_PER_SEC };

		cout << "��������� ����� ������ " << (int)time / 60 << " ����� " << time << " ������";
	}
}

int fib(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}