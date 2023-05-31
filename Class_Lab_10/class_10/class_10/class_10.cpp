#include <iostream>
#include <fstream>
#include <string>
#include "Money.h"
#include "file_work.h"
using namespace std;

void main()
{
	setlocale(0, "Rus");
	Money m,temp;
	int k, c, num, cnt;
	char file_name[30];
	do
	{					// меню
		cout << "\n5. Добавить к записей после элемента с заданным значением";
		cout << "\n4. Уменьшить все записи с заданным значением на 1 руб 50 коп";
		cout << "\n3. Удалить все записи, равные заданному значению"; 
		cout << "\n2. Вывести файл"; // печать файла
		cout << "\n1. Создать файл"; // создание файла
		cout << "\n0. Выход\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name? "; cin >> file_name; // задаем имя файла
			k = make_file(file_name); // вызов функции для записи в файл
			if (k < 0) cout << "can't make file\n"; // вывод сообщения об ошибке
			break;
		case 2: cout << "file name? "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "can't read file\n";
			break;
		case 3: cout << "file name? "; cin >> file_name;
			cout << "введите money";
			cin >> temp;
			k = del_file(file_name, temp);
			if (k < 0)cout << "can't read file\n";
			break;
		case 4: cout << "file name? "; cin >> file_name;
			cout << "введите money";
			cin >> temp;
			k = change_file(file_name,temp );
			if (k < 0) cout << "can't read file";
			break;
		case 5: cout << "file name? "; cin >> file_name;
			cout << "k?"; cin >> k;
			cout << "введите money: "; cin >> temp;
			int a = add_file(file_name, k,temp);
			if (a < 0) cout << "can't read file";
		}
		 
	} while (c != 0);
}