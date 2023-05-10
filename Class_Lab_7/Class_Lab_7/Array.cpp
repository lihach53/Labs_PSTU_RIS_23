#include <iostream>
#include "Array.h"
using namespace std;

/*template <class T>
Iterator<T>::Iterator() {
	elem = nullptr;
}

template <class T>
Iterator<T>::Iterator(const Iterator<T>& it) {
	elem = it.elem;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& it) const {
	return elem == it.elem;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& it) {
	return elem != it.elem;
}

template <class T>
void Iterator<T>::operator++() {
	++elem;
}

template <class T>
void Iterator<T>::operator--() {
	--elem;
}

template <class T>
void Iterator<T>::operator+=(int n) {
	for (int i = 1; i < n; ++i) {
		++elem;
	}
}

template <class T>
int& Iterator<T>::operator *() {
	return *elem;
}
*/

template <class T>
Array<T>::Array() {
	size = 0;
	data[size] = {};
/*  beg.elem = &data[0];
	end.elem = &data[size]; */
}


template <class T>
Array<T>::Array(int size) {
	this->size = size;
	data = new T[size];
	cout << "Enter array" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter " << i + 1 << " element: ";
		cin >> data[i];
	}
/*  beg.elem = &data[0];
	end.elem = &data[size]; */
}


template <class T>
Array<T>::Array(const Array<T>& other) {
	size = other.size;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
/*	beg = other.beg;
	end = other.end;*/
}

template <class T>
Array<T>::~Array() {
	delete[]data;
	data = 0;
}

/*template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this == &other) {
		return *this;
	}
	size = other.size;
	if (data != 0) {
		delete[]data;
	}
	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
	beg = other.beg;
	end = other.end;
	return *this;
}*/

template <class T>
int& Array<T>::operator[](int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	cout << "Error out of range";
}

template <class T>
bool Array<T>::operator!=(const Array<T>& a) const {
	return (size == a.size) && (data == a.data);
}

template <class T>
bool Array<T>::operator<(int x) const {
	for (int i = 0; i < size; i++) {
		if (data[i] = x) return 1;
	}
	return 0;
}

/*template <class T>
Iterator<T> Array<T>::first() {
	return beg;
}

template <class T>
Iterator<T> Array<T>::last() {
	return end;
}*/

template <class T>
ostream& operator<<(ostream& fout, const Array<T>& other) {
	for (int i = 0; i < other.size; i++) {
		fout << other.data[i];
	}
	fout << endl;
	return fout;
}

template <class T>
istream& operator>> (istream& fin, Array<T>& other) {
	for (int i = 0; i < other.size; i++) {
		fin >> other.data[i];
	}
	return fin;
}
