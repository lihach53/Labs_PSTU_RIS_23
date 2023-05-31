#pragma once
#include<iostream>
#include<stack>
#include<vector>
#include <cstdlib>
using namespace std;

template<class T>
class Vector
{
	stack<T> s;
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	void Print();
	void Sred();
	void add_to_end(T);

	void add_to_all(T);
	T Max();
	void Del(T);
};
template<class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

template<class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

template<class T>
Vector<T>::Vector() { len = 0; }

template<class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);
	}
	len = s.size();
}

template<class T>
Vector<T>::Vector(const Vector<T>& vec)
{
	vector<T> v;
	v.len = vec.len;
	v = copy_stack_to_vector(vec.s);
	s = copy_vector_to_stack(v);
}

template<class T>
void Vector<T>::Print()
{
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

template<class T>
T Vector<T>::Max()
{
	T m = s.top(); // присвоить значение вершины стека
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty()) {
		if (s.top() > m) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;

}

template<class T>
void Vector<T>::Del(T el)
{
	
	vector<T> v;
	T t;
	while (!s.empty()) {
		t = s.top();
		if (t != el)v.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}


template<class T>
void Vector<T>::add_to_end(T el)
{
	vector<T> v = copy_stack_to_vector(s);

	v.push_back(el);

	s = copy_vector_to_stack(v);
}
template<class T>
void Vector<T>::Sred()
{
	long rub_sum = 0;
	int kop_sum = 0;
	vector<T> v = copy_stack_to_vector(s);
	for (int i = 0; i < v.size(); i++)
	{
		rub_sum += v[i].get_rub();
		kop_sum += v[i].get_kop();
	}
	long a = rub_sum / v.size();
	int b = kop_sum / v.size();
	T sred_money(a, b);
	cout <<" среднее арифметическое равно: " <<  sred_money << endl;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		long r = v[i].get_rub() + sred_money.get_rub();
		int k = v[i].get_kop() + sred_money.get_kop();

		v[i].set_rubles(r);
		v[i].set_kop(k);
	}
	s = copy_vector_to_stack(v);
	
}

template<class T>
void Vector<T>::add_to_all(T sred)
{
	vector<T> v;
	T t;
	while (!s.empty()) {
		t = s.top();
		v.push_back(t + sred);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}