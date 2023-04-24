#include <iostream>
#include "Lenght.h"
using namespace std;

Lenght make_object(double F, double S) {
	Lenght t;
	t.Init(F, S);
	return t;
}

int main()
{
	double first, second;
	cout << "Enter x coordinate for first object: "; cin >> first;
	cout << "Enter y coordinate for first object: "; cin >> second;
	Lenght p = make_object(first, second);
	cout << "Enter x coordinate for second object: "; cin >> first;
	cout << "Enter y coordinate for second object: "; cin >> second;
	cout << "======================================"<<endl;
	cout << "Distance between objects: " << p.distance(first, second)<<endl;
	p.show();
}