#include "Plenty.h"
#include "Iterator.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "Rus");
	// недопустимый размер множества, превышен максимальный размер
	try
	{
		Plenty a(10);
	}
	catch (Error& e)
	{
		e.what();
	}

	cout << endl;

	// недопустимый размер множества, отрицательный размер
	try
	{
		Plenty b(-1);
	}
	catch (Error& e)
	{
		e.what();
	}

	cout << endl;

	// недопустимый индекс, слишком большой индекс
	try
	{
		Plenty c(5);
		int n = c[10];
	}
	catch (Error& e)
	{
		e.what();
	}

	cout << endl;

	// недопустимый индекс, отрицательный индекс недопустим
	try
	{
		Plenty d(5);
		int f = d[-1];
	}
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}