#include "Money.h"
#include "Container.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(0, "Rus");
	int n;
	cout << "n? "; cin >> n;
	Container <Money> s(n);
	s.Print();

	cout << "что удалить? " << endl;
	Money to_erase; cin >> to_erase;
	s.del_el(to_erase);
	s.Print();


	Money sred = s.sred();
	cout << "средн арифм = " << sred << endl;
	cout << "добавляем его ко всем элементам: " << endl;
	s.add_to_all(sred);
	s.Print();

}