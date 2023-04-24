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
	fout << other.first << "�" << other.second << "�" << other.third << "�" << endl;
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
		cout << "������ ������� ������ �������";
	}
	else {
		if (this->first == other.first) {
			if (this->second > other.second) {
				cout << "������ ������� ������ �������";
			}
			else {
				if (this->second == other.second) {
					if (this->third > other.third) {
						cout << "������ ������� ������ �������";
					}
					else {
						if (this->third == other.third) {
							cout << "�������� �����";
						}
						else {
							cout << "������ ������� ������ �������";
						}
					}
				}
				else {
					cout << "������ ������� ������ �������";
				}
			}
		}
		else {
			cout << "������ ������� ������ �������";
		}
	}
}

void Time::show() {
	cout << first << "�" << second << "�" << third << "�" << endl;
}