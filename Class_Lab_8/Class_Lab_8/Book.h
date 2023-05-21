#pragma once
#pragma once
#include "Print.h"
#include <string>
#include <iostream>
using namespace std;

class Book :
	public Print
{
public:
	Book(void);
public:
	~Book(void);
	void Show();
	void Input();
	Book(string, string, int, string);
	Book(const Book&);
	int Get_countpages();
	string Get_publishing_house();
	void Set_countpages(int);
	void Set_publishing_house(string);
	Book& operator=(const Book&);
protected:
	int countpages;
	string publishing_house;
};