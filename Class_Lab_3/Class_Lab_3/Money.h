#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money 
{
private:
	long rub;
	int kop;
public:
	//Конструкторы + деструктор
	Money();
	Money(long, int);
	Money(const Money& p);
	~Money();
	//Селекторы и модификаторы
	long Get_rub();
	int Get_kop();
	void Set_rub(long rub);
	void Set_kop(long kop);
	//Перегруженные операторы
	Money& operator-(double money);
	Money& operator=(const Money& p);
	bool operator==(const Money& p);
	bool operator!=(const Money& p);
	//Перегруженные методы ввода/вывода
	friend ostream& operator<<(ostream& fout, const Money& p);
	friend istream& operator>>(istream& fin, Money& p);
};