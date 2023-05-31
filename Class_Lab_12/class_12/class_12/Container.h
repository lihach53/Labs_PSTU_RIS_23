#pragma once
#include <iostream>
#include <set>
#include "Money.h"
using namespace std;


template<class T>
class Container
{
	set<T, less<T>> s;

	int len;
public:
	Container(void);
	Container(int n);
	Container(const Container<T>& c);
	void Print();
	~Container(void);

	T sred();
	void del_el(T);
	void add_to_all(  T);
};

template<class T>
Container<T>::Container() { len = 0; }

template<class T>
Container<T>::~Container()
{
}

template<class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}
	len = s.size();
}

template<class T>
Container<T>::Container(const Container<T>& c)
{
	len = c.len;
	for (auto it = s.begin(); it != s.end(); it++) {
		*it = c.*it;
	}
}
template<class T>
void Container<T>::Print()
{
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}



template<class T>
void Container<T>::del_el(T value) {
	auto it = s.find(value); // Поиск элемента по значению
	if (it != s.end()) { // Если элемент найден
		s.erase(it); // Удаление элемента
	}
}

template<class T>
T Container<T>::sred()
{
	T sum;
	int r = (int)s.size();
	for (T m : s) {
		sum = sum + m;
	}
	T res = sum / r;
	return res;
}

template<class T>
void Container<T>::add_to_all(T t)
{
	set<T, less<T>> res;
	for (auto i : s)
	{
		T y = i;
		res.insert(y + t);
	}
	s = res;
}

