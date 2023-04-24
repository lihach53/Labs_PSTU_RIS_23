#pragma once
#include <iostream>
#include "Object.h"
#include "Triad.h"
using namespace std;

class Vector
{
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(object*); 
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	object** beg;
	int size;
	int cur; 
};
