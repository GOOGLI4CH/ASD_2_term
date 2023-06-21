#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Задание 1" << endl;

	int N, sum = 0;
	cout << "Введите кол-во покупок: ";
	cin >> N;
	vector<int> list_check;
	srand(time(0));

	cout << "Чек:\n";
	for (int i = 0; i < N; i++)
	{
		list_check.push_back(rand() % 100);

		cout << list_check[i] << " ";
	}
	cout << endl;

	sort(list_check.begin(), list_check.end());
	reverse(list_check.begin(), list_check.end());

	int N1 = N;
	vector<int> new_list_check;
	cout << "Отсортированный чек:\n";
	if (N % 2 == 0)
	{
		N--;
		for (int i = 0; i < N; i++)
		{
			new_list_check.push_back(list_check[i]);
			sum += list_check[i];
			new_list_check.push_back(list_check[N]);
			N--;
		}
	}
	else
	{
		N--;
		for (int i = 0; i < N - 1; i++)
		{
			new_list_check.push_back(list_check[i]);
			sum += list_check[i];
			new_list_check.push_back(list_check[N]);
			N--;
		}
		new_list_check.push_back(list_check[N1 - 1]);
		sum += list_check[N1 - 1];
	}
	for (int i = 0; i < N1; i++)
	{
		cout << new_list_check[i] << " ";
	}
	cout << endl;
	cout << "Сумма чека: " << sum << endl;


	cout << "Задание 2" << endl;

	int col;
	vector<int> olympics_grade;
	cout << "Введите кол-во участников: ";
	cin >> col;

	for (int i = 0; i < col; i++)
	{
		olympics_grade.push_back(rand() % 100);
	}
	cout << endl;
	int max = *max_element(olympics_grade.begin(), olympics_grade.end());
	sort(olympics_grade.begin(), olympics_grade.end());
	reverse(olympics_grade.begin(), olympics_grade.end());
	cout << "Результаты олимпиады:\n";
	for (int i = 0; i < col; i++)
	{
		cout << olympics_grade[i] << " ";
	}
	int i = 0, count = 0;
	bool flag = true;
	cout << "Баллы победителей: ";

	while (olympics_grade[i] == max && flag)
	{
		cout << max << " ";
		if (olympics_grade[i + 1] != max)
		{
			max = olympics_grade[i + 1];
			count++;
		}
		if (count == 3) 
		{
			flag = false;
		}
		i++;
	}
}

