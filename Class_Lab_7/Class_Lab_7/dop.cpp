/*#pragma once
#include <ctime>
#include <iostream>
using namespace std;
template<class T>
class Plenty
{
private:
	T size;
	T* array;
public:

	Plenty(T size);



	~Plenty() { delete[] array; size = 0; }

	int& operator [](int index);
	void operator!=(const Plenty& rhs);
	void operator<(int num) const;

	friend ostream& operator<<(ostream& out, const Plenty<T>& a);
	friend istream& operator>>(istream& in, Plenty<T>& a);

	virtual void show()
	{
		cout << "Ìíîæåñòâî: ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << array[i];
		}
		cout << endl;
	}
};

template<class T>	
Plenty<T>::Plenty(T size)
{
	this->size = size;
	array = new T[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
	}
}

// îïåðàöèÿ ïðîâåðêè íà íåðàâåíñòâî
template<class T>
void Plenty<T>::operator!=(const Plenty& rhs) {
	bool f = false;
	int i = 0;
	while (!f) {
		if (array[i] != rhs.array[i]) f = true;
		i++;
	}
	if (f == 1)  cout << "Ìíîæåñòâà íå ðàâíû." << endl;
	else cout << "Ìíîæåñòâà ðàâíû." << endl;
}

// îïåðàöèÿ äîñòóïà ïî èíäåêñó
template<class T>
int& Plenty<T>::operator [](int index)
{
	if (index >= 0 && index < size)
	{
		return array[index];
	}
	else
	{
		cout << endl << "Error" << endl;
	}
}

// ïðîâåðêà ÷èñëà íà ïðèíàäëåæíîñòü ìíîæåñòâó
template<class T>
void Plenty<T>::operator<(int num) const
{
	bool f = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == num) {
			f = 1;
			cout << "×èñëî " << num << " ïðèíàäëåæèò ìíîæåñòâó." << endl << endl;
			break;
		}
	}
	if (f == 0) { cout << "×èñëî " << num << " íå ïðèíàäëåæèò ìíîæåñòâó. " << endl << endl; }
}

template<class T>
ostream& operator<<(ostream& out, const Plenty<T>&a)
{
	for (int i = 0; i < a.size; ++i)
	{ 
		out << a.array[i] << " ";
	}
	return out;
}
template<class T>
istream& operator>>(istream& in, Plenty<T>&a)
{
	for (int i = 0; i < a.size; ++i)
	{
		in >> a.array[i];
	}
	return in;
}
*/