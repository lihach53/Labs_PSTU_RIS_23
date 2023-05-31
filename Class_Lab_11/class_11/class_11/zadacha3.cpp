#include "Money.h"
#include <iostream>
#include <ctime>
#include "Vector.h"

void main3()
{
	setlocale(0, "Rus");
	srand(time(NULL));
	
	Vector<Money>vec(5); 
	vec.print_vector();
	cout << endl;

	cout << "добавили максимальный элемент в конец:" << endl;
	vec.max_find();
	vec.print_vector();

	Money to_erase; int pos_erase;
	cout << "что удалить? "; cin >> to_erase;
	pos_erase = vec.find_pos(to_erase);
	vec.del_el(pos_erase);
	vec.print_vector();

	cout << "найдем среднее арифметическое и добавим его ко всем элементам вектора:" << endl;
	
	
	vec.sred();
	vec.print_vector();
}


