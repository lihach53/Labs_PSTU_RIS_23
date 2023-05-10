#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*template <class T>
class Iterator
{
	friend class Array<T>;
private:
	T* elem;
public:
	Iterator();
	Iterator(const Iterator<T>& it);
	bool operator==(const Iterator<T>& it) const;
	bool operator!=(const Iterator<T>& it);
	void operator++();
	void operator--();
	void operator+=(int n);
	int& operator *();
};*/

template <class T>
class Array
{
private:
	int size;
	T* data;
/*	Iterator<T> beg;
	Iterator<T> end;*/
public:
	Array();
	Array(int size);
	Array(const Array<T>& other);
	~Array();
	//Array<T>& operator=(const Array<T>& other);
	int& operator[](int index);
	bool operator!=(const Array<T>& a) const;
	bool operator<(int) const;
	friend ostream& operator<<(ostream& fout, const Array<T>& other);
	friend istream& operator>>(istream& fin, Array<T>& other);
/*	Iterator<T> first();
	Iterator<T> last();*/
};
