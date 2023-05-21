#pragma once
#include "Book.h"
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

struct Node
{
	Node* prev, * next;
	Object* data;
};

class List
{
public:
	List();
	~List();
	void Add();
	void Del();
	void Show();
	int operator()();
	void pushback(Object* other);
	void Get_name();
	//void HandleEvent(const TEvent& e);
protected:
	int size;
	Node* head, * tail;
};

