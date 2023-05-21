#pragma once
#include "List.h"
#include "Event.h"
#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

class Dialog :
	public List
{
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int Endstate;
}; 
