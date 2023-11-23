#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");
	int n,x=0,m,min=0,max=0,mas[30],count=1;
	cout << " Введите n" << endl;
	cin >> n;
	m = n;
	max = n;
	mas[0] = n;
	n = n / 2;
	mas[1] = n;
	while (x != 3)
	{
		cout << n <<endl;
		cout << "1 - много, 2 - мало 3, - угадал" << endl;
		cin >> x;
		if (x == 1)
		{
			max = n;
			n = (min + max) / 2;
			count++;
			mas[count] = n;
		}
		if (x == 2)
		{
			min = n;
			n = (min + max) / 2;
			count++;
			mas[count] = n;
		}
		if (x == 3)
		{
			count++;
			break;
		}
	}
	int y = 0;
	cout << endl;
	for (int i = 0; i < count; i++)
		cout << mas[i] << endl;
	while (m != 1)
	{
		m = m / 2;
		y++;
	}
	cout << "Максимальное количество шагов " << y+1;
}