#include "Money.h"
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
using namespace std;

void main()
{
    setlocale(0, "Rus");
    Vector<Money>v(3);
    v.Print();

    cout << "max = " << v.Max() << endl;
    cout << "add max to the end: " << endl;
    v.add_to_end(v.Max());
    v.Print();

    Money to_erase;
    cout << "введите элемент который нужно удалить: "; cin >> to_erase;
    v.Del(to_erase);
    v.Print();

    v.Sred();
   
    cout << "прибавляем среднее арифметическое ко всем элементам: " << endl;
    
    v.Print();
}
