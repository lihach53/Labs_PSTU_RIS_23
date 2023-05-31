#include <iostream>
#include <deque>
#include <cstdlib>
#include "Money.h"
using namespace std;

typedef deque<Money> deq; // определяем тип для работы с очередью
deq make_deque(int n)
{
	deq d;
	for (int i = 0; i < n; i++)
	{
		long r = rand() % 10000;
		int k = rand() % 100;
		Money a(r,k);
		d.push_back(a);
	}
	return d;
}

void print_deque(deq d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i]<< " ";
	cout << endl;
}

deq max_find(deq d)
{
	Money maxim = d[0];
	for (int i = 1; i < d.size(); i++)
	{
		if (d[i] > maxim)
			maxim = d[i];
	}
	d.push_back(maxim);
	return d;
}

deq del_el(deq d, Money val)
{
	for (deque<Money>::iterator it = d.begin(); it != d.end();)
	{
		if (*it == val)
			it = d.erase(it);
		else
			it++;
	}
	return d;
}

deq sred(deq d)
{
	long rub_sum = 0;
	int kop_sum = 0;
	for (int i = 0; i < d.size(); i++)
	{
		rub_sum += d[i].get_rub();
		kop_sum += d[i].get_kop();
	}
	long a = rub_sum / d.size();
	int b = kop_sum / d.size();
	Money sred_money(a,b) ;
	cout << sred_money;
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		long r = d[i].get_rub() + sred_money.get_rub();
		int k = d[i].get_kop() + sred_money.get_kop();
		
		d[i].set_rubles(r);
		d[i].set_kop(k);
	}
	return d;
}

void main2()
{
	setlocale(0, "Rus");
	srand(time(NULL));
	try {
		deque<Money> d;
		deque<Money>::iterator di = d.begin();
		int n;
		cout << "n? "; cin >> n;
		d = make_deque(n);
		print_deque(d);
		d = max_find(d);
		print_deque(d);
		Money m;
		cout << "введите элемент, который нужно удалить из очереди: " << endl; cin >> m;

		cout << "Удалили элемент " << m << endl;
		d = del_el(d, m);
		print_deque(d);
		cout << endl;

		cout << "Прибавили среднее арифмеитческое ко всем элементам. " << endl;
		d = sred(d);
		print_deque(d);
	}
	catch(int)
	{
		cout << "error!";
	}
}


