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
//����������
Print::~Print(void)
{
}
//���������� � �����������
Print::Print(string name, string writer)
{
	this->name = name;
	this->writer = writer;
}
//����������� �����������
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

//���������
string Print::Get_name() {
	return name;
}
string Print::Get_writer() {
	return writer;
}
//������������
void Print::Set_writer(string writer)
{
	this->writer = writer;
}
void Print::Set_name(string name)
{
	this->name = name;
}

//�������� ������������
Print& Print::operator=(const Print& c)
{
	if (&c == this)return *this;
	name = c.name;
	writer = c.writer;
	return *this;
}
//����� ��� ��������� ���������
void Print::Show()
{
	cout << "\nNAME : " << name;
	cout << "\nWRITER : " << writer;
	cout << "\n";
}
//����� ��� ����� �������� ���������
void Print::Input()
{
	cout << "\nNAME:";
	getline(cin, name);
	cout << "\nWRITER:";
	getline(cin, writer);
}