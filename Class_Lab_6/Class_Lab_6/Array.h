#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Iterator
{
	friend class Array;
private:
	int* elem;
public:
	Iterator();
	Iterator(const Iterator& it);
	bool operator==(const Iterator& it) const;
	bool operator!=(const Iterator& it);
	void operator++();
	void operator--();
	void operator+=(int n);
	int& operator *();
};


class Array
{	
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	Array();
	Array(int size);
	Array(const Array& other);
	~Array();
	int& operator[](int index);
	bool operator!=(const Array& a) const;
	bool operator<(int) const;
	friend ostream& operator<<(ostream& fout, const Array& other);
	friend istream& operator>>(istream& fin, Array& other);
	Iterator first();
	Iterator last();
};

