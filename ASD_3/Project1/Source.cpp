#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

void quicksort(int* mas, int first, int last);

void main()
{
	srand((unsigned int)time(NULL));
	setlocale(LC_CTYPE, "ru");
	int n;
	cout << "Введите n" << endl;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];
	int* D = new int[n];
	int* E = new int[n];

	for (int i = 0; i < n; i++)
		*(A + i) = rand() % 100 - 50;
	cout << "Исходный массив" << endl;
	for (int i = 0; i < n; i++)
		cout << *(A + i) << "\t";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		*(B + i) = *(A + i);
		*(C + i) = *(A + i);
		*(D + i) = *(A + i);
		*(E + i) = *(A + i);
	}

	cout << "Пузырьковая сортировка" << endl;
	clock_t start = clock();
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (*(B + j) > *(B + j + 1))
				swap(*(B + j), *(B + j + 1));
	clock_t end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC<<endl;
	for (int i = 0; i < n; i++)
		cout << *(B + i) << "\t";
	cout << endl;
	cout << "Cортировка вставкой" << endl;
	int buff;
	start = clock();
	for (int i = 1; i < n; i++)
	{
		buff = C[i];
		for (int j = i - 1; j >= 0 && C[j] > buff; j--)
		{
			C[j + 1] = C[j];
			C[j + 1] = buff;
		}
	}
	end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < n; i++)
		cout << *(B + i) << "\t";
	cout << endl;
	cout << "Cортировка выбором" << endl;
	int min,num;
	start = clock();
	for (int i = 0; i < n; i++)
	{
		min = D[i];
		num = i;
		for (int k = i+1; k < n; k++)
		{
			if (D[k] < min)
			{
				min = D[k];
				num = k;
			}
		}
		swap(D[i], D[num]);
	}
	end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < n; i++)
		cout << *(B + i) << "\t";
	cout << endl;
	cout << "Быстрая сортировка" << endl;
	start = clock();
    quicksort(E, 0, n);
	end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < n; i++)
		cout << *(B + i) << "\t";
	cout << endl;
}

void quicksort(int* mas, int first, int last) {     //функция сортировки
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; 				//вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) 				//перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}

