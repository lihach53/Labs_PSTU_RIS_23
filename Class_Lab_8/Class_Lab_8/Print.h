#pragma once
#pragma once
#include "Object.h"
#include <string>
using namespace std;

class Print : public Object
{
public:
	Print(void);//конструктор без параметров
public:
	virtual ~Print(void);//деструктор
	//void HandleEvent(const TEvent& e);
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	void Input();//функция для ввода значений атрибутов
	Print(string, string);//конструктор с параметрами
	Print(const Print&);//конструктор копирования
	//селекторы
	string Get_name();
	string Get_writer();
	//модификаторы
	void Set_name(string);
	void Set_writer(string);
	Print& operator=(const Print&);//перегрузка операции присваивания
protected:
	string name;
	string writer;
};