#pragma once
#include <iostream>
#include <fstream>
#include "Triad.h"
using namespace std;

class Time : Triad
{
public:
	Time();
	Time(int, int, int);
	Time(Time& other);
	~Time();

	//Перегрузка сравнения
	void operator||(const Time& other);
	//Перегрузка ввода-вывода
	friend ostream& operator<<(ostream& fout, const Time& other);
	friend istream& operator>>(istream& fin, Time& other);
	//
	void show();
};