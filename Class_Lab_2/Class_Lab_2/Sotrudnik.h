#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sotrudnik 
{
private:
	string fio;
	string dolzhnost;
	double zarplata;
public:
	Sotrudnik();
	Sotrudnik(string, string, double);
	Sotrudnik(const Sotrudnik& p);
	~Sotrudnik();
	string get_fio();
	string get_dolzhnost();
	double get_zarplata();
	void set_fio(string);
	void set_dolzhnost(string);
	void set_zarplata(double);
	void show();
};