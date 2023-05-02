#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

//////////////////////////////////////// ���� �� ������ ������������ �������

#define NMAX 100

typedef struct Stack {
	float arr[NMAX];
	int top;
}Stack;

void init(Stack* stack) {
	stack->top = 0;
}

void push(Stack* stack, float val) {  // ���������� �������� � ����
	if (stack->top < NMAX) {
		stack->arr[stack->top] = val;
		stack->top++;
	}
	else
		cout << "���� �����, ���������� ���������: " << stack->top << "!" << endl;
}

float pop(Stack* stack) { // �������� �������� �� �����
	float elem;
	if (stack->top > 0) {
		stack->top--;
		elem = stack->arr[stack->top];
		return elem;
	}
	else {
		cout << "���� ���� !" << endl;
		return 0;
	}
}

int Get_count(Stack* stack) { // ���-�� ��������� � �����
	return stack->top;
}

int Is_empty(Stack* stack) { // �������� �� �������
	if (stack->top = 0) cout << "���� ���� !";
	else return 0;
}

void Stack_print(Stack* stack) { // ����� ��������� �����
	int val = stack->top;
	if (stack->top = 0) return;
	else {
		while (val > 0) {
			val--;
			cout << stack->arr[val] << " ";
		}
	}
}

int Get_top(Stack* stack) {
	if ((stack->top) > 0) {
		return stack->arr[stack->top - 1];
	}
	else {
		cout << "���� ����!";
		return 0;
	}
}

int main() {
	Stack* stack = new Stack;
	setlocale(LC_ALL, "Ru");
	int i, n;
	float elem;
	init(stack);
	cout << "������� ���������� ��������� � �����: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "������� �������: ";
		cin >> elem;
		push(stack, elem);
	}
	cout << "� ����� ������� ���������: " << Get_count(stack) << endl;
	pop(stack);
	cout << "������ �������:" << Get_count(stack) << endl;
	Stack_print(stack);
	cout << endl << "������� �������: " << Get_top(stack) << endl;
	return 0;
}