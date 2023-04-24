#include <iostream>
#include <fstream>
#include "Money.h"
using namespace std;

int main() {
	Money a;
	Money b;
	Money c;
	cout << "Enter a:" << endl;
	cin >> a;
	cout << "Enter b:" << endl;
	cin >> b;
	cout << "Enter c:" << endl;
	cin >> c;
	c = a;
	(a == b) ? cout << "a==b" << endl : cout << "a!=b"<<endl;
	(a == c) ? cout << "a==c" << endl : cout << "a!=c" << endl;
	cout << "b - 24.25 = " << b - 24.25 << endl;
	cout << "a= "<< a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}