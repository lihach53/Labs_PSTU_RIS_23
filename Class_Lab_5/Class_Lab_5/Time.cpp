#include <iostream>
#include <fstream>
#include "Time.h"
using namespace std;

Time::Time() :Triad() {

}

Time::Time(int first, int second, int third) : Triad(first, second, third) {

}

Time::Time(Time& other) :Triad(other) {

}

Time::~Time() {

}

ostream& operator<<(ostream& fout, const Time& other) {
	fout << other.first << "ч" << other.second << "м" << other.third << "с" << endl;
	return fout;
}

istream& operator>>(istream& fin, Time& other) {
	cout << "Enter hours:";
	fin >> other.first;
	cout << "Enter minutes:";
	fin >> other.second;
	cout << "Enter seconds:";
	fin >> other.third;
	return fin;
}

void Time::operator||(const Time& other) {
	if (this->first > other.first) {
		cout << "ѕервый элемент больше второго";
	}
	else {
		if (this->first == other.first) {
			if (this->second > other.second) {
				cout << "ѕервый элемент больше второго";
			}
			else {
				if (this->second == other.second) {
					if (this->third > other.third) {
						cout << "ѕервый элемент больше второго";
					}
					else {
						if (this->third == other.third) {
							cout << "Ёлементы равны";
						}
						else {
							cout << "ѕервый элемент меньше второго";
						}
					}
				}
				else {
					cout << "ѕервый элемент меньше второго";
				}
			}
		}
		else {
			cout << "ѕервый элемент меньше второго";
		}
	}
}

void Time::show() {
	cout << first << "ч" << second << "м" << third << "с" << endl;
}