#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct Node {
	string field;
	Node* next;
}Node;

typedef struct Queue {
	struct Node* head, * tail;
}Queue;

void init(Queue* queue) {
	queue->head = nullptr;
	queue->tail = nullptr;
}

int empty(Queue* queue) {
	if (queue->head == 0)
		return 1;
	else
		return 0;
}

void addelem(Queue* queue, string x) {
	Node* tmp = new Node;
	tmp->field = x;
	tmp->next = nullptr;

	if (queue->head != nullptr) {
		queue->tail->next = tmp;
		queue->tail = tmp;
	}
	else {
		queue->head = queue->tail = tmp;
	}
}

void print(Queue* queue) {
	Node* tmp = queue->head;
	while (tmp != nullptr) {
		cout << tmp->field << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void delelem(Queue* queue) {
	cout << "Удалённый элемент:" << endl;
	if (queue->head != nullptr) {
		Node* tmp = queue->head;
		cout << tmp->field << endl;
		queue->head = queue->head->next;
		delete tmp;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Ru");
	Queue* queue = new Queue;
	init(queue);
	addelem(queue, "one 111111");
	addelem(queue, "two 222222");
	print(queue);
	delelem(queue);
	delelem(queue);
	cout << "После:";
	print(queue);
	return 0;
}