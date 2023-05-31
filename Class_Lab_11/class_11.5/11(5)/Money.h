#pragma once
#pragma once
#include <iostream>
using namespace std;

class Money
{
public:
	Money(void);
	Money(long, int);
	Money(const Money&);
	Money& operator=(const Money&);

	long get_rub() { return rubles; }
	int get_kop() { return kop; }
	void set_rubles(long r) { rubles = r; }
	void set_kop(int k) { kop = k; }
	friend ostream& operator<<(ostream& out, const Money&);
	friend istream& operator>>(istream& in, Money&);
	virtual ~Money(void) { rubles = 0; kop = 0; };


	bool operator!=(const Money& t);
	bool operator==(const Money& t);
	bool operator<(const Money& t);
	bool operator>(const Money& t);
	Money& operator+(const Money& t);
	Money& operator/(int);
	Money& operator/(const Money& t);
private:
	long rubles;
	int kop;
};
