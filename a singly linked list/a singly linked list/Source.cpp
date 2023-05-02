#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	string field;
	Node* next;
}Node;

typedef struct List {
	struct Node* head;
	int size;
}List;

void init(struct Node* node, struct List* list) {
	node->field = "";
	list->head = node;
	list->size = 0;
	node->next = nullptr;
}

void insert(struct List* list, string elem) {
	Node* temp = new Node;
	temp->field = elem;
	if (list->size == '0') {
		list->head = temp; // Действующий узел 
		list->head->next = temp; // Следующий узел
	}
	else {
		struct Node* p = list->head; // предыдущий узел указывает на создаваемый 
		temp->next = p; // узел указывает на след. эл.
		list->head = temp;
	}
	list->size++;
}

void print(struct List* list) {
	Node* tmp = list->head;
	for (int i = 0; i < list->size; i++) {
		cout << tmp->field << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

struct Node* listsearch(struct List* list, int key) {
	Node* tmp = list->head;
	int i = 1;
	while (i < key && tmp != 0) {
		tmp->next = tmp;
	} return tmp;
}

void remove_first(struct List* list) { // Удаление первого элемента
	if (list->size == '0') return;
	Node* DelElem = list->head;
	list->head = DelElem->next;
	delete(DelElem);
	list->size--;
}

void remove_last(struct List* list) { // Удаление последнего элемента
	if (list->size == '0') return;
	Node* DelElem = list->head;
	int i = 1;
	while (i < list->size) {
		DelElem = DelElem->next;
		i++;
	}
	DelElem->next = nullptr;
	delete(DelElem);
	list->size--;
}

void remove(struct List* list, int position) {
	Node* tmp = list->head;
	Node* hren = list->head->next;
	int i = 1;
	while (i < position) {
		tmp = tmp->next;
		hren = hren->next;
		i++;
	}
	hren->next = tmp->next;
	delete (hren);
}

int main() {
	Node* node = new Node;
	List* list = new List;
	init(node, list);
	string elem = "zero";
	string elem1 = "first";
	string elem2 = "second";
	string elem3 = "third";
	string elem4 = "four";
	string elem5 = "five";
	setlocale(LC_ALL, "Russian");
	//cout << "Введите элемент, который хотите записать: ";
	//cin >> elem;
	insert(list, elem);
	insert(list, elem1);
	insert(list, elem2);
	insert(list, elem3);
	insert(list, elem4);
	insert(list, elem5);
	print(list);
	remove_first(list);
	print(list);
	remove_last(list);
	print(list);
	int position;
	cin >> position;
	remove(list, position);
	print(list);
	delete(node);
	delete(list);
	return 0;
}