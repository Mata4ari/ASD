#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;

#define INT_MAX 32767
#define INT_MIN 10000

struct baza {
	int num=NULL;
	string fio;
	baza* next=nullptr;
};

int has(int x, int SIZE)
{
	return (x % (SIZE - 1));
}

void ins(baza* A,int SIZE)
{
	int x;
	string str;
	baza* p;
	cout << "Введите номер" << endl;
	cin >> x;
	if (x<INT_MIN || x>INT_MAX)
	{
		cout << "Некорректный номер телефона" << endl;
		return;
	}
	cout << "Введите ФИО" << endl;
	cin.ignore();
	getline(cin, str);
	int n = has(x, SIZE);
	if (A[n].num == NULL)
	{
		A[n].fio = str;
		A[n].num = x;
	}
	else {
		baza* t = new (baza);
		p = A[n].next;
		if(p!=nullptr)
		{
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = t;
			t->next = nullptr;
			t->fio = str;
			t->num = x;
		}
		else
		{
			A[n].next = t;
			t->next = nullptr;
			t->fio = str;
			t->num = x;
		}
	}
}

void print(baza* A, int SIZE)
{
	baza* p;
	for (int i = 0; i < SIZE; i++)
	{
		if (A[i].num != NULL)
		{
			cout << A[i].fio << " " << A[i].num;
			if (A[i].next == nullptr)
				cout << endl;
			else
			{
				p = A[i].next;
				while (p != nullptr)
				{
					cout << "\t" << p->fio << " " << p->num;
					p = p->next;
				}
				cout << endl;
			}
		}
	}
}

void poshuk(baza* A, int SIZE)
{
	int x,n;
	baza* p;
	cout << "Введите номер для поиска" << endl;
	cin >> x;
	clock_t start = clock();
	n = has(x, SIZE);
	p = A[n].next;
	if (A[n].num == x)
		{
			cout << A[n].fio << " " << A[n].num << endl;
			clock_t end = clock();
			cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
			return;
		}
	while (p != nullptr)
	{
		if (p->num == x)
		{
			cout << p->fio << " " << p->num << endl;
			clock_t end = clock();
			cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
			return;
		}
		p = p->next;
	}
	cout << "Такого номера нет" << endl;
	clock_t end = clock();
	cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
}

void del(baza* A, int SIZE)
{
	int x, n;
	cout << "Введите номер удаляемого элемента" << endl;
	cin >> x;
	n = has(x, SIZE);
	baza* p = A[n].next,*t;
	if (A[n].num == x)
	{
		if (A[n].next == nullptr)
		{
			A[n].fio.clear();
			A[n].num = NULL;
		}
		else
		{
			A[n].fio = p->fio;
			A[n].num = p->num;
			A[n].next = p->next;
		}
		return;
	}
	if (p!=nullptr)
	{
		if (p->num == x)
		{
			A[n].next = p->next;
			delete p;
			return;
		}
		t = p;
		p = p->next;
		if (p->num == x)
		{
			t->next = p->next;
			delete p;
			return;
		}
		while (p != nullptr)
		{
			if (p->num == x)
			{
				t->next = p->next;
				delete p;
				return;
			}
			t = p;
			p = p->next;
		}
	}
	cout << "Такого номера нет" << endl;
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int SIZE;
	cin >> SIZE;
	baza* p = new baza[SIZE];
	int choice = -1;
	while (true)
	{
		cout << "1-добавление элемента" << endl;
		cout << "2-вывод таблицы" << endl;
		cout << "3-поиск по номеру" << endl;
		cout << "4-удаление по номеру" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		if (choice == 1)
			ins(p,SIZE);
		if (choice == 2)
			print(p, SIZE);
		if (choice == 3)
		{
			poshuk(p, SIZE);
		}
		if (choice == 4)
			del(p, SIZE);
	}
}