#include <iostream>
#include <time.h> 
using namespace std;
int fib(int n);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int x,n;
	long a = 0, a1 = 1, temp = 0;
	cout << "1 - Цикл, 2 - Рекурсия" << endl;
	cin >> x;
	if (x!=1&&x!=2)
	{
		cout << "Ошибка";
		return (0);
	}
	cout << "Введите номер числа Фибоначчи" << endl;
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
		cout << "N число =" << temp << endl;
		clock_t end{ clock() };
		int time{ (end - start) / CLOCKS_PER_SEC };

		cout << "Расчетное время циклом " << (int)time / 60 << " минут " << time << " секунд";
	}
	else if (x == 2)
	{
		clock_t start{ clock() };
		int i = 0;
		cout << "N число =" << fib(n) << endl;
		clock_t end{ clock() };
		int time{ (end - start) / CLOCKS_PER_SEC };

		cout << "Расчетное время циклом " << (int)time / 60 << " минут " << time << " секунд";
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