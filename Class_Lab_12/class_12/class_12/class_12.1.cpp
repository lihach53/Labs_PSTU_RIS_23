#include <set>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef set<int, less<int>> tset;
tset::iterator it;

set<int> make_set(int n)
{
	tset s;
	int a;
	for (int i = 0; i < n; i++) {
		cout << "введите элемент множества: "; cin >> a;
		s.insert(a);
	}
	return s;
}

void print_set(tset s)
{
	for (it = s.begin(); it != s.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void del_el(tset&  s, int to_erase)
{
	auto it = s.find(to_erase);
	if (it != s.end()) { // если элемент найден
		s.erase(it);
	}
	else {
		cout << "элемент не найден" << endl;
	}
}
int sred(tset& s)
{
	int sum = 0;
	int r = s.size();
	for (it = s.begin(); it != s.end(); it++) {
		sum += *it;
	}
	return sum / r;
}

void add_to_all(tset& s, int sr)
{
	set<int> temp;

	for (auto el : s) {
		temp.insert(el + sr);
	}

	s = temp;
}

void main1()
{
	setlocale(0, "Rus");
	// третья задача не имеет смысла, т.к. в множестве все элементы упорядочены по возрастанию, и максимальный элемент всегда в конце множества, а также, если добавить его в конец,
	// то он удалится, потому что в множестве автоматически удаляются совпадающие значения!!!

	int n;
	cout << "n? "; cin >> n;
	tset myset = make_set(n);
	print_set(myset);

	int to_erase;
	cout << "что удалить? "; cin >> to_erase;
	del_el(myset, to_erase);
	print_set(myset);

	int sr = sred(myset);
	cout << "среднее арифметическое равно: " << sr << endl;
	cout << "добавляем его ко всем элементам множества:" << endl;
	add_to_all(myset, sr);
	print_set(myset);
}

