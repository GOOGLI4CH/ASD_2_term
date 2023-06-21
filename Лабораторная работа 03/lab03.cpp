#include <iostream>
#include <chrono>

using namespace std;

void quickSort(int* numbers, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
	{
		quickSort(numbers, left, pivot - 1);
	}
	if (right > pivot)
	{
		quickSort(numbers, pivot + 1, right);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int choice = 0;
	int size;
	cout << "Введите размер массивов: "; cin >> size;
	int* A = new int[size], * B = new int[size], * C = new int[size], * D = new int[size], * E = new int[size];
	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Сгенерировать и вывести массив" << endl;
		cout << "2 - Пузырьковая сортировка" << endl;
		cout << "3 - Сортировка методом Шелла" << endl;
		cout << "4 - Сортировка выбором" << endl;
		cout << "5 - Быстрая сортировка" << endl;
		cout << "6 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Массив A:" << endl;
			for (int i = 0; i < size; i++)
			{
				*(A + i) = *(B + i) = *(C + i) = *(D + i) = *(E + i) = rand() % 100;
				cout << *(A + i) << " ";
			}
			cout << endl;
			break;
		}
		case 2:
		{
			int temp;

			auto start = chrono::high_resolution_clock::now();

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size - 1; j++)
				{

					if (*(B + j) > *(B + j + 1))
					{
						temp = *(B + j);
						*(B + j) = *(B + j + 1);
						*(B + j + 1) = temp;
					}
				}
			}

			auto end = chrono::high_resolution_clock::now();

			chrono::duration<double> duration = end - start;

			cout << "Массив B (пузырьковая сортировка):" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << *(B + i) << " ";
			}
			cout << endl << "Затраченное время: " << duration.count() << "s.ms" << endl;
			break;
		}
		case 3:
		{
			int tmp, step, j;

			auto start = chrono::high_resolution_clock::now();

			for (step = size / 2; step > 0; step /= 2)
			{
				for (int i = step; i < size; i++)
				{
					tmp = *(C + i);
					for (j = i; j >= step; j -= step)
					{
						if (tmp < *(C + j - step))
						{
							*(C + j) = *(C + j - step);
						}
						else
						{
							break;
						}
					}
					*(C + j) = tmp;
				}
			}

			auto end = chrono::high_resolution_clock::now();

			chrono::duration<double> duration = end - start;

			cout << "Массив C (метод Шелла):" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << *(C + i) << " ";
			}
			cout << endl << "Затраченное время: " << duration.count() << "s.ms" << endl;
			break;
		}
		case 4:
		{
			auto start = chrono::high_resolution_clock::now();

			int count, key;
			for (int i = 0; i < size - 1; i++)
			{
				count = *(D + i);
				key = i;
				for (int j = i + 1; j < size; j++)
				{
					if (*(D + j) < *(D + key))
					{
						key = j;
					}
				}
				if (key != i)
				{
					*(D + i) = *(D + key);
					*(D + key) = count;
				}
			}

			auto end = chrono::high_resolution_clock::now();

			chrono::duration<double> duration = end - start;

			cout << "Массив D (сортировка выбором):" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << *(D + i) << " ";
			}
			cout << endl << "Затраченное время: " << duration.count() << "s.ms" << endl;
			break;
		}
		case 5:
		{
			auto start = chrono::high_resolution_clock::now();

			quickSort(E, 0, (size - 1));

			auto end = chrono::high_resolution_clock::now();

			chrono::duration<double> duration = end - start;

			cout << "Массив E (быстрая сортировка):" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << *(E + i) << " ";
			}
			cout << endl << "Затраченное время: " << duration.count() << "s.ms" << endl;
			break;
		}
		}
	} while (choice != 6);
}