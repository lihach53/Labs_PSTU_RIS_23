#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); // открыть для записи
	if (!stream) return -1; // ошибка открытия файла
	int n;
	Money m;
	cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m; // ввод атрибутов объекта из стандартного потока
		stream << m << "\n"; // запись объекта в файловый поток
	}
	stream.close(); // закрыть поток
	return n; // вернуть количество записанных объектов
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m; int i = 0; string n;
	while (stream>>m)
	{
		cout << m << " ";
		++i;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Money t)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	int i = 0;
	long c = t.get_rubles();
	int d = t.get_kop();
	Money m;
	while (stream >> m) // пока нет конца файла выполняем чтение файла
	{
		// если прочитан признак конца файла, то выход из цикла
		if (stream.eof()) break;
		i++;
		// если номер объекта не равен к, то записываем его в вспомогательный файл
		long a = m.get_rubles();
		int b = m.get_kop();
		if ((a != c) || (b != d))
		{
			temp << m;
		}
	}
	stream.close();
	temp.close();
	
	remove(f_name); // удалить старый файл
	rename("temp", f_name);
	
	return i; // количество прочитанных
	
}

int change_file(const char* f_name, Money& t)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m; int i = 0, l = 0;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		if (m != t) temp << m;
		else temp << ++m;
	}
	stream.close(); temp.close();
	
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_file(const char* f_name, int k, Money& t)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Money m; int i = 0;
	long c = t.get_rubles();
	int d = t.get_kop();
	while (stream >> m)
	{
		long a = m.get_rubles();
		int b = m.get_kop();
		if ((a != c) || (b != d))
		{
			temp << m;
			i++;
		}		
		else
		{	
			temp << m;
			for (int j = 0; j < k; j++)
			{
				cout << "введите money: "; 
				Money n;
				cin >> n;
				temp << n;
				i++;
			}
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

