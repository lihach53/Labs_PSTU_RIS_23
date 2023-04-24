#include <iostream>

using namespace std;

struct Node {
	double data;
	Node* next, * prev;

	Node(double data);
	~Node();
};

Node::Node(double data) {
	this->data = data;
	this->next = this->prev = NULL;
}

Node::~Node() {

}

struct Linked_list_2 {
	Node* head, * tail;

	Linked_list_2();
	~Linked_list_2();

	void pop_front();
	void pop_back();
	void push_back(double data);
	void push_front(double data);
	Node* getNode(int index);
	void erase(int index);
	void insert(int index, double data);
	int countElem();
};

Linked_list_2::Linked_list_2() {
	this->head = this->tail = NULL;
}

Linked_list_2::~Linked_list_2() {
	while (head != NULL) {
		pop_front();
	}
}

void Linked_list_2::push_front(double data) {
	Node* ptr = new Node(data);
	ptr->next = head;
	if (head != NULL) {
		head->prev = ptr;
	}
	if (tail == NULL) {
		tail = ptr;
	}
	head = ptr;

}

void Linked_list_2::push_back(double data) {
	Node* ptr = new Node(data);
	ptr->prev = tail;
	if (tail != NULL) {
		tail->next = ptr;
	}
	if (head == NULL) {
		head = ptr;
	}
	tail = ptr;


}

void Linked_list_2::pop_back() {
	if (tail == NULL) return;
	Node* ptr = tail->prev;
	if (ptr != NULL) {
		ptr->next = NULL;
	}
	else {
		head = NULL;
	}
	delete tail;
	tail = ptr;
}

void Linked_list_2::pop_front() {
	if (head == NULL) return;
	Node* ptr = head->next;
	if (ptr != NULL) {
		ptr->prev = NULL;
	}
	else {
		tail = NULL;
	}
	delete head;
	head = ptr;
}

Node* Linked_list_2::getNode(int index) {
	int k = 0;
	Node* ptr = head;
	while (k != index) {
		if (ptr->next == NULL) {
			return ptr;
		}
		ptr = ptr->next;
		k++;
	}
	return ptr;
}

void Linked_list_2::erase(int index) {
	Node* right, * left;
	Node* ptr = getNode(index);
	if (ptr == NULL) {
		return;
	}
	if (ptr == tail) {
		pop_back();
		return;
	}
	if (ptr == head) {
		pop_front();
		return;
	}
	left = ptr->prev;
	right = ptr->next;
	left->next = right;
	right->prev = left;
	delete ptr;
}

void Linked_list_2::insert(int index, double data) {
	Node* right, * left;
	right = getNode(index);
	if (right == NULL) {
		return push_back(data);
	}
	left = right->prev;
	if (left == NULL) {
		return push_front(data);
	}
	Node* ptr = new Node(data);
	ptr->next = right;
	right->prev = ptr;
	ptr->prev = left;
	left->next = ptr;

}

int Linked_list_2::countElem() {
	int count = 1;
	Node* ptr = head;
	do {
		count++;
		ptr = ptr->next;
	} while (ptr->next != NULL);
	return count;
}


void Delete2Elem(int index, Linked_list_2& list) {
	list.erase(index - 1);
	list.erase(index);
}

Linked_list_2 AddK(int k, Linked_list_2& list) {
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
	return list;
}

void CoutList(Linked_list_2& list) {
	Node* ptr = list.head;
	while (ptr != NULL) {
		ptr = ptr->next;
		cout << ptr->data << " ";
	}
	cout << endl;

}

int main()
{
	Linked_list_2 list;

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
			cout << "Enter index element: ";
			cin >> l;
			AddK(l, list);
			break;
		case 10:
			return 0;

		}
	}
}