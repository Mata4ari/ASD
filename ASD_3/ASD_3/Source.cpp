#include <iostream>
#include <ctime>
#include <time.h>
#include <functional>

using std::endl; using std::cin; using std::cout;

int* bubble_sort(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
    return a;
}

int* shell_sort(int* b, int n)
{
    int j, i, d = n;
    d = d / 2;
    while (d > 0)
    {
        for (i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && b[j] > b[j + d])
            {
                std::swap(b[j], b[j + d]);
                j--;
            }
        }
        d = d / 2;
    }
    return b;
}

int* selection_sort(int* c, int n)
{
    int i, j, count, key;
    for (i = 0; i < n - 1; i++)
    {
        count = c[i];
        key = i;
        for (j = i + 1; j < n; j++)
        {
            if (c[j] < c[key]) { key = j; }
        }
        if (key != i)
        {
            std::swap(c[i], count);
        }
    }
    return c;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            std::swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    std::swap(a[pIndex], a[end]);

    return pIndex;
}

void quick_sort(int* d, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = partition(d, start, end);

    quick_sort(d, start, pivot - 1);
    quick_sort(d, pivot + 1, end);
}

std::function<int* (int*, int)> sort_function[3] = { bubble_sort, shell_sort, selection_sort };

int main()
{
    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "ru");

    int n = NULL; cout << "Введите количество элементов: "; cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10 + 1;
        cout << array[i] << '\t';
    }

    int* a = new int[n];

    cout << endl;
    clock_t start = clock();
    a = sort_function[0](array, n);
    clock_t end = clock();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
    cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC;

    cout << endl;
    start = clock();
    a = sort_function[1](array, n);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
    cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC;

    cout << endl;
    start = clock();
    a = sort_function[2](array, n);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
    cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC;

    cout << endl;
    start = clock();
    quick_sort(array, array[0], array[n]);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC;
}
