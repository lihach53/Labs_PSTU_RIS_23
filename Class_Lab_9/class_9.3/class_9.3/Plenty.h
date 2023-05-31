#pragma once
#include "Iterator.h"
const int MAX_SIZE = 6;
class Plenty
{
private:
	int size;
	int* array;
	Iterator beg;
	Iterator end;

public:
	Plenty(int size);
	Plenty(const Plenty& p);
	~Plenty();

	const Plenty& operator=(const Plenty& p);
	void show();


	int& operator [](int index);
	Iterator first();
	Iterator last();
	bool operator!=(const Plenty& rhs);
	bool operator<(int num) const;


};
