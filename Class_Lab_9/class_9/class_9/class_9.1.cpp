#include<iostream>
#include<ctime>
#include "Iterator.h"
#include "Plenty.h"
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size = 10;

	try
	{
		Plenty a(size); // ошибка с кодом 1
		
	}
	catch (int num)
	{
		cout << "Ошибка с кодом: " << num << endl;
		cout << "1 - выбранный размер множества недопустим. 2 - выбранный индекс недопустим." << endl;
	}
	try
	{
		Plenty a(5);
		int n = a[6];
	}
	catch (int num)
	{
		cout << "Ошибка с кодом: " << num << endl;
		cout << "1 - выбранный размер множества недопустим. 2 - выбранный индекс недопустим." << endl;
	}

	

	return 0;
}
