#include "List.h"
#include "Event.h"
#include "Book.h"
#include "Dialog.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "m - ������� ������" << endl;
	cout << "+ - �������� � ������" << endl;
	cout << "- - ������� �� ������" << endl;
	cout << "s - �������� ������" << endl;
	cout << "q - �����" << endl;
	Dialog D;
	D.Execute();
}