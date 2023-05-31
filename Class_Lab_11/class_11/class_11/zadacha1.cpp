#include <iostream>
#include <cstdlib>
#include <deque>
#include <ctime>

using namespace std;

typedef deque<int> deq;
deq make_deq(int n)
{
	deq d;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 - 50;
		d.push_back(a);
	}
	return d;
}

void print_deque(deq d)
{
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

deq max_find(deq d)
{
	int maxim = -100000;
	
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] > maxim)
			maxim = d[i];
	}
	d.push_back(maxim);
	return d;
}


deq del_el(deq d ,int val)
{
	for (deque<int>::iterator it = d.begin(); it != d.end();)
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
	int sum = 0;
	for (int i = 0; i < d.size(); i++)
	{
		sum += d[i];
	}
	double sred = (float)sum / d.size();
	cout << sred << endl;
	for (int i = 0; i < d.size(); i++)
	{
		d[i] += sred;
	}
	return d;
}



void main1()
{
	setlocale(0,"Rus");
	srand(time(NULL));
	try {
		deque<int> d;
		deque<int>::iterator di = d.begin();
		int n;
		cout << "n? "; cin >> n;
		d = make_deq(n);
		print_deque(d);
		d = max_find(d);
		print_deque(d);
		int del_elem;
		cout << "введите число, которое нужно удалить: "; cin >> del_elem;
		d = del_el(d, del_elem);
		print_deque(d);
		d = sred(d);
		print_deque(d);
	}
	catch (int)
	{
		cout << "error";
	}
}