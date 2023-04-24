#include <iostream>
#include <fstream>
#include "Triad.h"
using namespace std;

Triad::Triad() {
	first = 0;
	second = 0;
	third = 0;
}

Triad::Triad(int first, int second, int third) {
	this->first = first;
	this->second = second;
	this->third = third;
}

Triad::Triad(Triad& other) {
	first = other.first;
	second = other.second;
	third = other.third;
}

Triad::~Triad() {

}

void Triad::set_first(int first) {
	this->first = first;
}

void Triad::set_second(int second) {
	this->second = second;
}

void Triad::set_third(int third) {
	this->third = third;
}

int Triad::get_first() {
	return first;
}

int Triad::get_second() {
	return second;
}

int Triad::get_third() {
	return third;
}

Triad& Triad::operator=(const Triad& other) {
	first = other.first;
	second = other.second;
	third = other.third;
	return *this;
}

ostream& operator<<(ostream& fout, const Triad& other) {
	fout << "first - " << other.first << "," << "second - " << other.second << "," << "third - " << other.third << endl;
	return fout;
}

istream& operator>>(istream& fin, Triad& other) {
	cout << "Enter first:";
	fin >> other.first;
	cout << "Enter second:";
	fin >> other.second;
	cout << "Enter third:";
	fin >> other.third;
	return fin;
}

void Triad::show() {
	
	cout << "\nfirst: " << first << endl;
	cout << "second: " << second << endl;
	cout << "third: " << third << endl << endl;
}
