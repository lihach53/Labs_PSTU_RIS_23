#include "List.h"
#include "Event.h"
#include "Book.h"
#include "Dialog.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "m - создать группу" << endl;
	cout << "+ - добавить в группу" << endl;
	cout << "- - удалить из группу" << endl;
	cout << "s - показать группу" << endl;
	cout << "q - выйти" << endl;
	Dialog D;
	D.Execute();
}