#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Money.h"
#include <numeric>
using namespace std;

typedef vector<Money> vecm;
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

vecm::iterator i;

vecm make_vector(int n)
{
	Money a;
	vecm v;
	for (int i = 0; i < n; i++) {
		a.set_rubles(rand() % 100000);
		a.set_kop(rand() % 100);
		v.push_back(a);
	}
	return v;
}

vecm max_find(vecm v)
{
	Money m;
	m = *max_element(v.begin(), v.end());
	v.push_back(m);
	return v;
}

void print_vector(vecm v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}

Money sred(vecm v)
{
	Money sum = accumulate(v.begin(), v.end(), Money(0, 0),
		[](const Money& sum, const Money& m) {
			return sum + m;
		});
	int n = v.size();
	return sum / n;
}

void add_to_all(vecm& v, Money sr) 
{
	std::transform(v.begin(), v.end(), v.begin(), [sr](Money value) {
		return value + sr; });
}

void main()
{
	setlocale(0, "Rus");
	srand(time(NULL));
	int n;
	cout << "n? "; cin >> n;

	vecm v;
	v = make_vector(n);
	print_vector(v);

	//  добавляем максимальный элемент в конец вектора

	v = max_find(v);
	print_vector(v);
	
	// удаляем элемент с заданным значением

	cout << "удаление: " << endl;
	cout << "что удалить?" << endl;
	cin >> s;
	i = find_if(v.begin(), v.end(), Equal_s());
	v.erase(i);
	print_vector(v);

	// прибавляем среднее арифметическое ко всем элементам

	Money sr = sred(v);
	cout << "среднее арифметическое равно: " << sr << endl;
	cout << "прибавляем ко всем элементам: " << endl;
	add_to_all(v, sr);
	print_vector(v);

	// сортировка

	cout << "сортировка по возрастанию: " << endl;
	sort(v.begin(), v.end());
	print_vector(v);

	cout << "сортировка по убыванию: " << endl;
	sort(v.begin(), v.end(), Comp_less());
	print_vector(v);
}