#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Triad
{
protected:
	int first;
	int second;
	int third;
public:
	Triad();
	Triad(int first, int second, int third);
	Triad(Triad& other);
	~Triad();
	//Модификаторы
	void set_first(int);
	void set_second(int);
	void set_third(int);
	int get_first();
	int get_second();
	int get_third();
	//Перегрузка присваивания
	Triad& operator=(const Triad& other);
	//Перегрузка ввода-вывода
	friend ostream& operator<<(ostream& fout, const Triad& other);
	friend istream& operator>>(istream& fin, Triad& other);
	//
	void show();
};