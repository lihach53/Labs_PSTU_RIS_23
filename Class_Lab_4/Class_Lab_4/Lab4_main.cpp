#include <iostream>
#include "Time.h"
#include "Triad.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "");
	Time t1;
	cin >> t1;
	cout << "Object t1: " << t1 << endl;
	Time t2(12, 30, 10);
	cout << "Object t2: " << t2 << endl;
	t1 = t2;
	cout << "Obnovlenniy Object t1: " << t1;
	cout << "\n";
	cout << "Sravnenie t1 è t2" << endl;
	t1 || t2;
	cout << "\n";
	Time t3(7, 32, 10);
	cout << "Object t3: " << t3 << endl;
	cout << "Sravnenie t1 è t3" << endl;
	t1 || t3;
	cout << "\n";
	return 0;
}