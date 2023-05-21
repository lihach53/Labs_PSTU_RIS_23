#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

Book::Book(void) {
	name = "";
	writer = "";
	countpages = 0;
	publishing_house = "";
}

Book::~Book(void) {

}

Book::Book(string name, string writer, int countpages, string publishing_house) {
	this->name = name;
	this->writer = writer;
	this->countpages = countpages;
	this->publishing_house = publishing_house;
}

Book::Book(const Book& other) {
	name = other.name;
	writer = other.writer;
	countpages = other.countpages;
	publishing_house = other.publishing_house;
}

int Book::Get_countpages() {
	return countpages;
}

string Book::Get_publishing_house() {
	return publishing_house;
}

void Book::Set_countpages(int countpages) {
	this->countpages = countpages;
}

void Book::Set_publishing_house(string publishing_house) {
	this->publishing_house = publishing_house;
}

Book& Book::operator=(const Book& other) {
	name = other.name;
	writer = other.writer;
	countpages = other.countpages;
	publishing_house = other.publishing_house;
	return *this;
}

void Book::Show() {
	cout << "\nNAME : " << name;
	cout << "\nWRITER : " << writer;
	cout << "\nCOUNTPAGES : " << countpages;
	cout << "\nPUBLISHING HOUSE : " << publishing_house;
	cout << "\n";
}

void Book::Input() {
	cout << "\nNAME: ";
	getline(cin, name);
	cout << "\nWRITER: ";
	getline(cin, writer);
	cout << "\nCOUNTPAGES: ";
	cin >> countpages;
	cin.ignore();
	cout << "\nPUBLISHING HOUSE: ";
	getline(cin, publishing_house);
}