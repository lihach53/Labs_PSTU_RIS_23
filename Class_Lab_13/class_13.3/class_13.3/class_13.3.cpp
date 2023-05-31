#include <set>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Money.h"
#include <numeric>
using namespace std;

typedef set<Money, less<Money>> mset;
mset::iterator it;
Money s;

struct Greater_s // больше, чем s
{
	bool operator() (Money t)
	{
		if (t > s) return true; else return false;
	}
};


struct Equal_s
{
	bool operator()(Money m)
	{
		return m == s;
	}
};

mset make_set(int n)
{
	mset s;
	Money a;
	for (int i = 0; i < n; i++) {
		cout << "введите элемент множества: "; cin >> a;
		s.insert(a);
	}
	return s;
}

void print_set(mset s)
{
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void del_el(mset& mySet, Money value) {
	auto it = mySet.find(value); // Поиск элемента по значению
	if (it != mySet.end()) { // Если элемент найден
		mySet.erase(it); // Удаление элемента
	}
}


Money sred(mset s)
{
	Money sum = accumulate(s.begin(), s.end(), Money(0, 0),
		[](const Money& sum, const Money& m) {
			return sum + m;
		});
	int n = s.size();
	return sum / n;
}

void add_to_all(mset& s, Money sr)
{
	std::transform(s.begin(), s.end(), s.begin(), [sr](Money value) {
		return value + sr; });
}

void main()
{
	setlocale(0, "Rus");
	// третья задача не имеет смысла, т.к. в множестве все элементы упорядочены по возрастанию, и максимальный элемент всегда в конце множества, а также, если добавить его в конец,
	// то он удалится, потому что в множестве автоматически удаляются совпадающие значения!!!

	// создаем множество и заполняем его элементами 

	int n;
	cout << "n? "; cin >> n;
	mset myset = make_set(n);
	print_set(myset);

	// удаление 

	cout << "удаление: " << endl;
	cout << "что удалить?" << endl; cin >> s;
	it = remove_if(myset.begin(), myset.end(), Equal_s());
	myset.erase(it, myset.end());
	print_set(myset);

	// находим среднее арифметическое и прибавляем ко всем элементам множества

	Money sr = sred(myset);
	cout << "среднее арифметическое равно: " << sr << endl;
	cout << "добавляем его ко всем элементам множества:" << endl;
	add_to_all(myset, sr);
	print_set(myset);
}