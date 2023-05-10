#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<int> A(5);
	cout << "A:" << A << endl;

	/*#include<iostream>

#include "Plenty.h"
#include "Money.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int k, size = 5,  n = 0;
	cout << "Введите k - индекс множества: "; cin >> k;
	Plenty<int> a(size);
	// вывод множества а
	a.show();
	cout << endl << "Число с выбранным индексом: " << a[k] << endl;
	cout << "Введите число, которое хотите проверить на принадлежность множетству: "; cin >>  n;
	a < n; 

	cout << "Проверка операции равенства множеств." << endl;
	Plenty<int> b(size);
	b.show();

	Plenty<int> c(size);
	c.show();

	b != c;

	cout << "Тестирование класса Money:" << endl;

	Money t1;
	cin >> t1;
	cout << "Первый экземпляр класса Money:" << endl;
	cout << t1; cout << endl;

	Money t2;
	cin >> t2;
	cout << "Второй экзепляр класса Money: " << endl;
	cout << t2; cout << endl;

	cout << "Проверка их на неравенство: " << endl;
	t1 != t2;

	return 0;
}*/
}