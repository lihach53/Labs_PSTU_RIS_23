#pragma once
#include "List.h"
#include <string>
#include <iostream>
using namespace std;

List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::~List() {
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void List::pushback(Object* other) {
	Node* newNode = new Node;
	newNode->data = other;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
	}
}

void List::Del() {
	if (head != nullptr) {
		Node* curr = tail;
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
	}
}

void List::Add() {
	Object* p;
	cout << "1.Print" << endl;
	cout << "2.Book" << endl;
	int y;
	cin >> y;
	cin.ignore();
	if (y == 1) {
		Print* a = new(Print);
		a->Input();
		p = a;
		pushback(p);
	}
	else {
		if (y == 2) {
			Book* b = new(Book);
			b->Input();
			p = b;
			pushback(p);
		}
	}
}

void List::Show() {
	if (size == 0) {
		cout << "Empty" << endl;
	}
	Node* node = head;
	Object* p = head->data;
	while (node != nullptr) {
		p = node->data;
		p->Show();
		node = node->next;
	}
}

int List::operator()() {
	return size;
}

void List::Get_name() {
	Node* node = head;
	Object* p = head->data;
	while (node != nullptr) {
		p = node->data;
		p->Get_name();
		node = node->next;
	}
}


/*void List::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		Node* node = head;
		Object* p = head->data;
		while (node != nullptr) {
			p = node->data;
			p->HandleEvent(e);
			node = node->next;
		}
	}
}*/

//for (Node* node = head; node != nullptr; node = node->next)