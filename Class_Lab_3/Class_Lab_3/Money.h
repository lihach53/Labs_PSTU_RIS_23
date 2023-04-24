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
	//������������ + ����������
	Money();
	Money(long, int);
	Money(const Money& p);
	~Money();
	//��������� � ������������
	long Get_rub();
	int Get_kop();
	void Set_rub(long rub);
	void Set_kop(long kop);
	//������������� ���������
	Money& operator-(double money);
	Money& operator=(const Money& p);
	bool operator==(const Money& p);
	bool operator!=(const Money& p);
	//������������� ������ �����/������
	friend ostream& operator<<(ostream& fout, const Money& p);
	friend istream& operator>>(istream& fin, Money& p);
};