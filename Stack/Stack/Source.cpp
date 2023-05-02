#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

//////////////////////////////////////// СТЭК НА ОСНОВЕ СТАТИЧЕСКОГО МАССИВА

#define NMAX 100

typedef struct Stack {
	float arr[NMAX];
	int top;
}Stack;

void init(Stack* stack) {
	stack->top = 0;
}

void push(Stack* stack, float val) {  // Добавление элемента в стэк
	if (stack->top < NMAX) {
		stack->arr[stack->top] = val;
		stack->top++;
	}
	else
		cout << "Стек полон, количество элементов: " << stack->top << "!" << endl;
}

float pop(Stack* stack) { // Удаление элемента из стэка
	float elem;
	if (stack->top > 0) {
		stack->top--;
		elem = stack->arr[stack->top];
		return elem;
	}
	else {
		cout << "Стэк пуст !" << endl;
		return 0;
	}
}

int Get_count(Stack* stack) { // Кол-во элементов в Стэке
	return stack->top;
}

int Is_empty(Stack* stack) { // Проверка на пустоту
	if (stack->top = 0) cout << "Стэк Пуст !";
	else return 0;
}

void Stack_print(Stack* stack) { // Вывод элементов стэка
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
		cout << "Стэк пуст!";
		return 0;
	}
}

int main() {
	Stack* stack = new Stack;
	setlocale(LC_ALL, "Ru");
	int i, n;
	float elem;
	init(stack);
	cout << "Введите количество элементов в стеке: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Введите элемент: ";
		cin >> elem;
		push(stack, elem);
	}
	cout << "В стэке столько элементов: " << Get_count(stack) << endl;
	pop(stack);
	cout << "Теперь столько:" << Get_count(stack) << endl;
	Stack_print(stack);
	cout << endl << "Верхний элемент: " << Get_top(stack) << endl;
	return 0;
}