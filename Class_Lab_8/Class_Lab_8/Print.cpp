#include "Print.h"
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

Print::Print(void)
{
	name = "";
	writer = "";
}
//деструктор
Print::~Print(void)
{
}
//констрктор с параметрами
Print::Print(string name, string writer)
{
	this->name = name;
	this->writer = writer;
}
//конструктор копировани€
Print::Print(const Print& Print)
{
	name = Print.name;
	writer = Print.writer;
}

/*void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command) {
		case cmGet:
			cout << "NAME = " << Get_name() << endl;
			break;
		}
	}
}*/

//—електоры
string Print::Get_name() {
	return name;
}
string Print::Get_writer() {
	return writer;
}
//ћодификаторы
void Print::Set_writer(string writer)
{
	this->writer = writer;
}
void Print::Set_name(string name)
{
	this->name = name;
}

//оператор присваивани€
Print& Print::operator=(const Print& c)
{
	if (&c == this)return *this;
	name = c.name;
	writer = c.writer;
	return *this;
}
//метод дл€ просмотра атрибутов
void Print::Show()
{
	cout << "\nNAME : " << name;
	cout << "\nWRITER : " << writer;
	cout << "\n";
}
//метод дл€ ввода значений атрибутов
void Print::Input()
{
	cout << "\nNAME:";
	getline(cin, name);
	cout << "\nWRITER:";
	getline(cin, writer);
}