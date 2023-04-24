#include "Sotrudnik.h"
#include <iostream>
#include <string>

using namespace std;

Sotrudnik make_sotrudnik() {
	string fio, dolzhnost;
	double zarplata;
	cout << "Enter FIO: "; getline(cin,fio);
	cout << "Enter dolzhnost: "; getline(cin,dolzhnost);
	cout << "Enter double: "; cin >> zarplata;
	Sotrudnik ex(fio, dolzhnost, zarplata);
	return ex;
}

void print_sotrudnik(Sotrudnik ex) {
	ex.show();
}

int main() 
{
	Sotrudnik s1;
	s1.show();
	Sotrudnik s2("Bulochkin Vasiliy Olegovich","Lawyer", 30000);
	s2.show();
	Sotrudnik s3 = s2;
	cout << "Dolzhnost s3: " << s3.get_dolzhnost() << endl;
	s3.set_fio("Tapochkin Oleg Viktorovich");
	s3.set_dolzhnost("Driver");
	s3.set_zarplata(100000);
	print_sotrudnik(s3);
	Sotrudnik s4 = make_sotrudnik();
	s4.show();
}