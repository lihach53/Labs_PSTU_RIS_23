#include <iostream>
#include "Array.h"
using namespace std;

int main() 
{
	Array arr1(7);
	cout << *(arr1.first()) << endl;
	Iterator it = arr1.first();
	++it;
	++it;
	cout << "*it: " << *it << endl;
	for (it = arr1.first(); it != arr1.last(); ++it) {
		cout << *it << "\t";
	}
	cout << endl;
	cout << arr1[3] << endl;
	cout << "Enter index for it: ";
	int n;
	cin >> n;
	it = arr1.first();
	it += n;
	cout << *it << endl;
	cout << "Enter number for check: ";
	cin >> n;
	if (arr1 < n) {
		cout << "Number in array";
	}
	else {
		cout << "Number out of array";
	}
	return 0;
}