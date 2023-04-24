#include <iostream>
#include <fstream>
#include "Money.h"
using namespace std;

Money::Money() {
	this->rub = 0;
	this->kop = 0;
}

Money::Money(long rub, int kop) {
	this->rub = rub;
	this->kop = kop;
}

Money::Money(const Money& p) {
	rub = p.rub;
	kop = p.kop;
}

Money::~Money() {

}

long Money::Get_rub() {
	return rub;
}

int Money::Get_kop() {
	return kop;
}

void Money::Set_rub(long rub) {
	this->rub = rub;
}

void Money::Set_kop(long kop) {
	this->kop = kop;
}

Money& Money::operator-(double money) {
	int celaya = (int)money; 
	int drobnaya = int((money - celaya) * 100.0);
	rub -= celaya;
	kop -= drobnaya;

	return *this;
}

Money& Money::operator=(const Money& p) {
	this->rub = p.rub;
	this->kop = p.kop;

	return *this;
}

bool Money::operator==(const Money& p) {
	return this->rub == p.rub && this->kop == p.kop;
}

bool Money::operator!=(const Money& p) {
	return !(this->rub == p.rub && this->kop == p.kop);
}

ostream& operator<<(ostream& fout, const Money& p) {
	fout << p.rub << "," << p.kop << "\n";
	return fout;
}

istream& operator>>(istream& fin, Money& p) {
	fin >> p.rub >> p.kop;
	return fin;
}