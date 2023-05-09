#include <iostream>
#include "Array.h"
using namespace std;

Iterator::Iterator() {
	elem = nullptr;
}

Iterator::Iterator(const Iterator& it) {
	elem = it.elem;
}

bool Iterator::operator==(const Iterator& it) const {
	return elem == it.elem;
}

bool Iterator::operator!=(const Iterator& it) {
	return elem != it.elem;
}

void Iterator::operator++() {
	++elem;
}

void Iterator::operator--() { 
	--elem;
}

void Iterator::operator+=(int n) {
	/*while (*elem != n) {
		++elem;
	}
	*/
	for (int i = 1; i < n; ++i) {
		++elem;
	}
}

int& Iterator::operator *() {
	return *elem;
}







Array::Array() {
	size = 0;
	data[size] = {};
	beg.elem = &data[0];
	end.elem = &data[size];
}


Array::Array(int size) {
	this->size = size;
	data = new int[size];
	cout << "Enter array" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter " << i + 1 << " element: ";
		cin >> data[i];
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}


Array::Array(const Array& other) {
	size = other.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
	beg = other.beg;
	end = other.end;
}

Array::~Array() {
	delete[]data;
	data = 0;
}

int& Array::operator[](int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	cout << "Error out of range";
}

bool Array::operator!=(const Array& a) const {
	return (size == a.size) && (data == a.data);
}

bool Array::operator<(int x) const {
	for (int i = 0; i < size; i++) {
		if (data[i] = x) return 1;
	}
	return 0;
}

Iterator Array::first() {
	return beg;
}

Iterator Array::last() {
	return end;
}

ostream& operator<<(ostream& fout, const Array& other) {
	for (int i = 0; i < other.size; i++) {
		fout << other.data[i];
	}
	fout << endl;
	return fout;
}

istream& operator>>(istream& fin, Array& other) {
	for (int i = 0; i < other.size; i++) {
		fin >> other.data[i];
	}
	return fin;
}
