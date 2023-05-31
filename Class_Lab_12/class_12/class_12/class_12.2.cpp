#include <set>
#include <cstdlib>
#include <iostream>
#include "Money.h"
using namespace std;

typedef set<Money, less<Money>> tset;
tset::iterator it;

tset make_set(int n)
{
	tset s;
	Money a;
	for (int i = 0; i < n; i++) {
		cout << "введите элемент множества: "; cin >> a;
		s.insert(a);
	}
	return s;
}

void print_set(tset s)
{
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void del_el(tset& mySet, Money value) {
	auto it = mySet.find(value); // Поиск элемента по значению
	if (it != mySet.end()) { // Если элемент найден
		mySet.erase(it); // Удаление элемента
	}
}


Money sred(tset s)
{
	Money sum = Money(0,0);
	int r = (int)s.size();
	for (Money m : s) {
		long rub_sum = sum.get_rub() + m.get_rub();
		int kop_sum = sum.get_kop() + m.get_kop();
		sum.set_rubles(rub_sum);
		sum.set_kop(kop_sum);
	}
	cout << "rubles sum: " << sum.get_rub() << "  kop sum: " << sum.get_kop() << endl;
	Money res(sum.get_rub() / (long)r, sum.get_kop() / (int)r);
	return res;
}

tset add_to_all(tset& s, Money sr)
{
	tset res;
	for (it = s.begin(); it != s.end(); it++) {
		Money m = *it;
		res.insert(m + sr);
	}
	return res;
	
}

void main2()
{
	setlocale(0, "Rus");
	// третья задача не имеет смысла, т.к. в множестве все элементы упорядочены по возрастанию, и максимальный элемент всегда в конце множества, а также, если добавить его в конец,
	// то он удалится, потому что в множестве автоматически удаляются совпадающие значения!!!

	int n;
	cout << "n? "; cin >> n;
	tset myset = make_set(n);
	print_set(myset);

	Money to_erase;
	cin >> to_erase;
	del_el(myset, to_erase);
	print_set(myset);

	Money sr = sred(myset);
	cout << "среднее арифметическое равно: " << sr << endl;
	cout << "добавляем его ко всем элементам множества:" << endl;
	myset = add_to_all(myset, sr);
	print_set(myset);
}