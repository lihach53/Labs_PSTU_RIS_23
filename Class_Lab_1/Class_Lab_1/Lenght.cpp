#include <iostream>
#include <math.h>
#include "Lenght.h"
using namespace std;

void Lenght::Init(double F, double S) {
	first_x = F;
	second_y = S;
}
void Lenght::read() {
	cout << "Enter X";
	cin >> first_x;
	cout << "Enter Y";
	cin >> second_y;
}
void Lenght::show() {
	cout << "\nX = " << first_x << "\nY = " << second_y;
	cout << endl;
}
double Lenght::distance(double x, double y) {
	return pow(pow(x-first_x,2)+pow(y-second_y,2),0.5);
}