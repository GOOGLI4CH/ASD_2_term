#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int bottom = 0, top = 0, N = 0, ans = 0, x = 0;
	cout << "Введите кол-во чисел" << endl;
	cin >> N;
	top = N;
	int maxSteps = ((int)log2(N) + 1), j = 0, * arr = new int[maxSteps];

	do
	{
		x = (bottom + top) / 2;
		*(arr + j) = x;
		j++;

		cout << "Ваше число " << x << "? (1 - мало, 2 - много, 3 - угадал)" << endl;
		cin >> ans;

		if (ans == 1)
		{
			bottom = x;
		}
		if (ans == 2)
		{
			top = x;
		}
		if (ans == 3)
		{
			cout << "Максимальное кол-во шагов " << maxSteps << endl;
			cout << "Кол-во шагов " << j << endl;
			for (int i = 0; i < j; i++)
			{
				cout << (i + 1) << "." << *(arr + i) << endl;
			}
			break;
		}
	} while (bottom < top);
}