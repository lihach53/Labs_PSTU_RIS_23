#include "Sotrudnik.h"
#include <iostream>
#include <string>

using namespace std;

Sotrudnik::Sotrudnik() {
	this->fio = "";
	this->dolzhnost = "";
	this->zarplata = 0;
}

Sotrudnik::Sotrudnik(string fio, string dolzhnost, double zarplata) {
	this->fio = fio;
	this->dolzhnost = dolzhnost;
	this->zarplata = zarplata;
}

Sotrudnik::Sotrudnik(const Sotrudnik& p) {
	fio = p.fio;
	dolzhnost = p.dolzhnost;
	zarplata = p.zarplata;
}

Sotrudnik::~Sotrudnik() {
	cout << "Destructor for object: " << this << endl;
}

string Sotrudnik::get_fio() {
	return fio;
}

string Sotrudnik::get_dolzhnost() {
	return dolzhnost;
}

double Sotrudnik::get_zarplata() {
	return zarplata;
}

void Sotrudnik::set_fio(string fio) {
	this->fio = fio;
}

void Sotrudnik::set_dolzhnost(string dolzhnost) {
	this->dolzhnost = dolzhnost;
}

void Sotrudnik::set_zarplata(double zarplata) {
	this->zarplata = zarplata;
}

void Sotrudnik::show() {
	cout << "FIO: " << fio << endl;
	cout << "Dolzhnost: " << dolzhnost << endl;
	cout << "Zarplata: " << zarplata << endl;
	cout << endl;
}
