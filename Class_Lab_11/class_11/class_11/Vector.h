#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<class T>
class Vector
{
	vector <T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	void print_vector();
	~Vector(void);
	void max_find();
	int find_pos(T);
	void del_el(int pos);
	void sred();


	


};

template<class T>
Vector<T>::Vector() { len = 0; }

template<class T>
Vector<T>::~Vector(void) {}

template<class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

template<class T>
void Vector<T>::print_vector()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "   ";
	cout << endl;
}

template<class T>
void Vector<T>::max_find()
{
	T maxim = v[0];

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > maxim)
		{
			maxim = v[i];
		}
	}
	v.push_back(maxim);
	
}

template<class T>
int Vector<T>::find_pos(T val)
{
	int pos = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == val) pos = i;
	}
	return pos;
}

template<class T>
void Vector<T>::del_el(int pos)
{
	v.erase(v.begin() + pos);
}

template<class T>
void Vector<T>::sred()
{
	long rub_sum = 0;
	int kop_sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		rub_sum += v[i].get_rub();
		kop_sum += v[i].get_kop();
	}
	long a = rub_sum / v.size();
	int b = kop_sum / v.size();
	T sred_money(a, b);
	cout << sred_money;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		long r = v[i].get_rub() + sred_money.get_rub();
		int k = v[i].get_kop() + sred_money.get_kop();

		v[i].set_rubles(r);
		v[i].set_kop(k);
	}
}





