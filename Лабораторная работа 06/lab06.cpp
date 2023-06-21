#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>
#include "HashTable.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	HashTable<person, int> table32(32);
	HashTable<person, int> table64(64);
	HashTable<person, int> table128(128);
	int choice = 0, num;
	string str;

	while (true)
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - Добавить элемент в хеш-таблицу" << endl;
		cout << "2 - Удалить элемент из хеш-таблицы" << endl;
		cout << "3 - Поиск элемента в хеш-таблице" << endl;
		cout << "4 - Вывод хеш-таблицы" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите номер: "; cin >> num;
			cin.ignore();
			cout << "Введите владельца: "; getline(cin, str);
			person human(num, str);
			table32.insert(human, num);
			table64.insert(human, num);
			table128.insert(human, num);
			break;
		}
		case 2:
		{
			cout << "Введите номер квартиры, которая подлежит удалению: "; cin >> num;
			table32.remove(num);
			table64.remove(num);
			table128.remove(num);
			break;
		}
		case 3:
		{
			cout << "Введите номер: "; cin >> num;
			cout << "Данные " << num << ": " << endl;

			cout << "Таблица 32: " << endl;
			auto start32 = std::chrono::high_resolution_clock::now();
			table32.printNode(table32.search(num));
			auto end32 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration32_ms = end32 - start32;
			cout << endl << "Время поиска в таблице 32" << duration32_ms.count() << " ms" << endl;

			cout << endl << "Таблица 64: " << endl;
			auto start64 = std::chrono::high_resolution_clock::now();
			table64.printNode(table64.search(num));
			auto end64 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration64_ms = end64 - start64;
			cout << endl << "Время поиска в таблице 64" << duration64_ms.count() << " ms" << endl;

			cout << endl << "Таблица 128: " << endl;
			auto start128 = std::chrono::high_resolution_clock::now();
			table128.printNode(table128.search(num));
			auto end128 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration128_ms = end128 - start128;
			cout << endl << "Время поиска в таблице 128" << duration128_ms.count() << " ms" << endl;
			break;
		}
		case 4:
		{
			cout << "Хеш-таблица 32:" << endl;
			table32.print();
			cout << endl << "Хеш-таблица 64:" << endl;
			table32.print();
			cout << endl << "Хеш-таблица 128:" << endl;
			table32.print();
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			break;
		}
	}
}