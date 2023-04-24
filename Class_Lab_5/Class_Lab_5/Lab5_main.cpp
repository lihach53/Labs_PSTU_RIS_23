#include <iostream>
#include "Object.h"
#include "Triad.h"
#include "Vector.h"
#include "Time.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	Vector v(5);
	Triad a;
	cin >> a;
	Time b;
	cin >> b;
	object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
}