#pragma once
class Iterator
{
private:
	friend class Plenty;
	int* elem;
public:

	Iterator();

	// перегрузка операции +n - переход вправо к элементу с номером n
	void operator+(int n);

	void operator++();
	void operator--();
	int& operator *() const;
	bool operator!=(const Iterator& it);
};
