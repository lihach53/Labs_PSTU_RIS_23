#include <iostream>

using namespace std;

class Node {
public:
	double data;
	Node* next;
public:
	Node(double data);
	~Node();
};

Node::Node(double data) {
	this->data = data;
	this->next = NULL;
}

Node::~Node() {

}

class Linked_list_1 {
public:
	Node* head, * tail;
public:
	Linked_list_1();
	~Linked_list_1();

	void pop_front();
	void pop_back();
	void push_back(double data);
	void push_front(double data);
	Node* getNode(int index);
	void erase(int index);
	void insert(int index, double data);
	int countElem();
};

Linked_list_1::Linked_list_1() {
	this->head = this->tail = NULL;
}

Linked_list_1::~Linked_list_1() {
	while (head != NULL) {
		pop_front();
	}
}

void Linked_list_1::push_front(double data) {
	Node* node = new Node(data);
	node->next = head;
	head = node;
	if (tail == NULL) tail = node;
}

void Linked_list_1::push_back(double data) {
	Node* node = new Node(data);
	if (head == NULL) head = node;
	if (tail != NULL) tail->next = node;
	tail = node;
}

void Linked_list_1::pop_back() {
	if (tail == NULL) return;
	if (head == tail) {
		delete tail;
		head = tail = NULL;
		return;
	}

	Node* node = head;
	for (; node->next != tail; node = node->next);

	node->next = NULL;
	delete tail;
	tail = node;
}

void Linked_list_1::pop_front() {
	if (head == NULL) return;

	if (head == tail) {
		delete tail;
		head = tail = NULL;
		return;
	}

	Node* node = head;
	head = node->next;
	delete node;
}

Node* Linked_list_1::getNode(int index) {
	if (index < 0) return NULL;

	Node* node = head;
	int n = 0;
	while (node && n != index && node->next) {
		node = node->next;
		n++;
	}
	if (n == index) {
		return node;
	}
	else {
		return NULL;
	}
}

void Linked_list_1::erase(int index) {
	if (index < 0) return;
	if (index == 0) {
		pop_front();
		return;
	}

	Node* left = getNode(index - 1);
	Node* node = left->next;
	if (node == NULL) return;

	Node* right = node->next;
	left->next = right;
	if (node == tail) tail = left;
	delete node;
}

void Linked_list_1::insert(int index, double data) {
	Node* left = getNode(index);
	if (left == NULL) return;

	Node* right = left->next;
	Node* node = new Node(data);

	left->next = node;
	node->next = right;
	if (right == NULL) tail = node;
}
/*
int Linked_list_2::countElem() {
	int count = 1;
	Node* ptr = head;
	do {
		count++;
		ptr = ptr->next;
	} while (ptr->next != NULL);
	return count;
}
*/

void Delete2Elem(int index, Linked_list_1& list) {
	list.erase(index - 1);
	list.erase(index);
}

void AddK(int k, Linked_list_1& list) {
	double data;
	for (int i = 0; i < k; i++) {
		data = 0;
		cout << "Enter frontlist data: ";
		cin >> data;
		list.push_front(data);
	}
	for (int i = 0; i < k; i++) {
		data = 0;
		cout << "Enter backlist data: ";
		cin >> data;
		list.push_back(data);
	}
}

void CoutList(Linked_list_1& list) {
	for (Node* ptr = list.head; ptr != NULL; ptr = ptr->next) {
		cout << ptr->data << " ";
	}
	cout << endl;

}

int main()
{
	Linked_list_1 list;

	int n = 0, k = 0, l = 0;
	double data = 0;
	while (true) {
		cout << "=================================================" << endl;
		cout << "Enter 1 to push_front" << endl;
		cout << "Enter 2 to push_back" << endl;
		cout << "Enter 3 to pop_front" << endl;
		cout << "Enter 4 to pop_back" << endl;
		cout << "Enter 5 to insert" << endl;
		cout << "Enter 6 to erase" << endl;
		cout << "Enter 7 to cout_list" << endl;
		cout << "Enter 8 to delete pre X and post X elements " << endl;
		cout << "Enter 9 to add X-elements in front and back of list " << endl;
		cout << "Enter 10 to complete" << endl;
		cout << "=================================================" << endl;
		cin >> n;
		switch (n) {
		case 1:
			data = 0;
			cout << "Enter data: ";
			cin >> data;
			list.push_front(data);
			break;
		case 2:
			data = 0;
			cout << "Enter data: ";
			cin >> data;
			list.push_back(data);
			break;
		case 3:
			list.pop_front();
			break;
		case 4:
			list.pop_back();
			break;
		case 5:
			data = 0;
			k = 0;
			cout << "Enter data: ";
			cin >> data;
			cout << "Enter index k: ";
			cin >> k;
			list.insert(k, data);
			break;
		case 6:
			k = 0;
			cout << "Enter data: ";
			cin >> k;
			list.erase(k);
			break;
		case 7:
			CoutList(list);
			break;
		case 8:
			l = 0;
			cout << "Enter index element: ";
			cin >> l;
			Delete2Elem(l, list);
			break;
		case 9:
			l = 0;
			cout << "Enter how much elem. you want to add: ";
			cin >> l;
			AddK(l, list);
			break;
		case 10:
			return 0;

		}
	}
}