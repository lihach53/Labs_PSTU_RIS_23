#include "Money.h"


Money::Money(void)
{
	rubles = 0;
	kop = 0;
}

Money::Money(long r, int k)
{
	rubles = r;
	kop = k;
}

Money::Money(const Money& t)
{
	rubles = t.rubles;
	kop = t.kop;
}

Money& Money::operator=(const Money& t)
{
	rubles = t.rubles;
	kop = t.kop;
	return *this;
}

ostream& operator<<(ostream& out, const Money& t)
{
	out << t.rubles << "," << t.kop;
	return out;
}

istream& operator>>(istream& in, Money& t)
{
	cout << "Введите рубли: "; in >> t.rubles;
	cout << "Введите копейки: "; in >> t.kop;
	return in;
}

bool Money::operator!=(const Money& t) const
{
	if (rubles == t.rubles && kop == t.kop) return false;
	else return true;
}

bool Money::operator==(const Money& t)
{
	if (rubles == t.rubles && kop == t.kop)  return true;
	else return false;
}
bool Money::operator<(const Money& other) const {    
	if (rubles == other.rubles) {
		return kop < other.kop;
	}
	return rubles < other.rubles;
}


bool Money::operator>(const Money& t) const
{
	if (rubles < t.rubles) return false;
	else if (rubles > t.rubles) return true;
	else {
		if (kop > t.kop) return true;
	}
}

Money Money::operator+(const Money& t) 
{
	Money tmp;
	tmp.rubles = rubles + t.rubles;
	tmp.kop = kop + t.kop;
	return tmp;
}

Money Money::operator/(int val)
{
	Money tmp;
	tmp.rubles = rubles / val;
	tmp.kop = kop / val;
	return tmp;
}

Money Money::operator+(const Money& t) const
{
	Money tmp;
	tmp.rubles = rubles + t.rubles;
	tmp.kop = kop + t.kop;
	return tmp;
}

