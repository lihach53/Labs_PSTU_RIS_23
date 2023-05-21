#pragma once

class Object
{
public:
	Object(void) {}
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual string Get_name() = 0;
	~Object(void) {}
};