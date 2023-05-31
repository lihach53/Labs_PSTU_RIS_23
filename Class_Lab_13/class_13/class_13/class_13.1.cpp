#include <deque>
#include <cstdlib>
#include <iostream>
#include "Money.h"
#include <algorithm>
#include <ctime>
#include <numeric>

using namespace std;

typedef deque<Money> deqm;
Money s;
struct Greater_s // больше, чем s
{
	bool operator() (Money t)
	{
		if (t > s) return true; else return false;
	}
};

struct Comp_less // для сортировки по убыванию
{
public:
	bool operator() (Money m1, Money m2)
	{
		if (m1 > m2) return true;
		else return false;
	}
};

struct Equal_s
{
	bool operator()(Money m)
	{
		return m == s;
	}
};




deqm make_deque(int n)
{
	Money a;
	deqm d;
	for (int i = 0; i < n; i++) {
		a.set_rubles(rand() % 100000);
		a.set_kop(rand()% 100 );
		d.push_back(a);
	}
	return d;
}

deqm max_find_add_to_end(deqm d)
{
	Money maxim;
	maxim = *max_element(d.begin(), d.end());
	d.push_back(maxim);
	return d;
}

void print_deque(deqm d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << endl;
	cout << endl;
}

void add_to_all(deqm& d, Money sr) {
	transform(d.begin(), d.end(), d.begin(), [sr](Money value) {
		return value + sr; });
}

deqm::iterator i;

Money sred(deqm d)
{
	Money sum = std::accumulate(d.begin(), d.end(), Money(0, 0),
		[](const Money& sum, const Money& m) {
			return sum + m;
		});
	int n = d.size();
	return sum / n;
}

void main()
{
	setlocale(0, "Rus");
	srand(time(NULL));
	int n;
	cout << "n? "; cin >> n;
	deqm d;
	d = make_deque(n);
	print_deque(d);

	deqm::iterator i;

	// добавление максимального элемента в конец очереди
	
	d = max_find_add_to_end(d);
	print_deque(d);


	// удаление элемента с заданным значением

	cout << "удаление: " << endl;
	cout << "что удалить?" << endl; cin >> s;
	i = remove_if(d.begin(), d.end(), Equal_s());
	d.erase(i, d.end());
	print_deque(d);

	// прибавить среднее арифметическое ко всем элементам

	Money sr = sred(d);
	cout << "среднее арифметическое равно: " << sr << endl;
	cout << "прибавляем ко всем элементам: " << endl;
	add_to_all(d, sr);
	print_deque(d);

	// сортировка
	cout << "сортировка по возрастанию: " << endl;
	sort(d.begin(), d.end());
	
	
	print_deque(d);

	cout << "сортировка по убыванию: " << endl;
	sort(d.begin(), d.end(), Comp_less());
	print_deque(d);
	
}