#include "Money.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef stack<Money>st;
typedef vector<Money>vec;

st make_stack(int n)
{
	st s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s.push(m);
	}
	return s;
}

// копируем стек в вектор
vec copy_stack_to_vector(st s)
{
	vec v;
	while (!s.empty())
	{
		// добавить в вектор элемент из вершины стека
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

// копирует вектор в стек
st copy_vector_to_stack(vec v)
{
	st s;
	for (int i = 0; i < v.size(); i++)
		s.push(v[i]); // добавить в стек элемент вектора
	return s;
}
void print_stack(st s)
{
	st temp = s;
	while (!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

st find_max(st s)
{
	Money maxim = s.top();

	st temp = s;
	while (!temp.empty()) {
		if (temp.top() > maxim)
			maxim = temp.top();
		temp.pop();
	}
	s.push(maxim);
	return s;
}

st del_el(st s, Money m, int n)
{
	st temp;
	while (!s.empty())
	{
		Money el = s.top();
		s.pop();

		if (el != m)
			temp.push(el);
		else n--;
	}
	while (!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
	return s;
}
st sred(st s, int n)
{
	long rub_sum = 0;
	int kop_sum = 0;
	st temp;

	// считаем сумму 
	while (!s.empty())
	{
		Money el = s.top();
		rub_sum += el.get_rub();
		kop_sum += el.get_kop();
		s.pop();
		temp.push(el);
	}
	
	long a = rub_sum / n;
	int b = kop_sum / n;
	cout << "среднее арифметическое равно: " << a << "," << b << endl;
	Money sred_money(a, b);
	cout << sred_money;
	cout << endl;

	while(!temp.empty())
	{
		long r = temp.top().get_rub() + sred_money.get_rub();
		int k = temp.top().get_kop() + sred_money.get_kop();

		Money new_money(r, k);
		s.push(new_money);
		temp.pop();
	}
	return s;
}
void main4()
{
	setlocale(0, "Rus");

	Money m;
	st s;
	int n;
	cout << "n? "; cin >> n;
	s = make_stack(n);
	print_stack(s);

	cout << "добавляем максимальный элемент стека в конец стека" << endl;
	s = find_max(s);
	print_stack(s);
	n++;

	Money to_erase;
	cout << "что удалить?"; cin >> to_erase;
	cout << endl;
	s = del_el(s, to_erase,n);
	print_stack(s);

	cout << "ищем среднее арифметическое и прибавляем его ко всем элементам стека: " << endl;
	s = sred(s,n);
	print_stack(s);
}