#pragma once
#pragma once
#include "Object.h"
#include <string>
using namespace std;

class Print : public Object
{
public:
	Print(void);//����������� ��� ����������
public:
	virtual ~Print(void);//����������
	//void HandleEvent(const TEvent& e);
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
	void Input();//������� ��� ����� �������� ���������
	Print(string, string);//����������� � �����������
	Print(const Print&);//����������� �����������
	//���������
	string Get_name();
	string Get_writer();
	//������������
	void Set_name(string);
	void Set_writer(string);
	Print& operator=(const Print&);//���������� �������� ������������
protected:
	string name;
	string writer;
};