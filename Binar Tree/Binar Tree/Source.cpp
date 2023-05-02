#include <iostream>
#include <stdlib.h>
constexpr auto MAXFIELD = 100;;
using namespace std;

typedef struct BinarTree {
	int field;
	BinarTree* left;
	BinarTree* right;
}BinarTree;

BinarTree* NewNode(int x) { // Создание узла
	BinarTree* tree = new BinarTree;
	tree->field = x;
	tree->left = nullptr;
	tree->right = nullptr;
	return tree;
}

BinarTree* insert(BinarTree* tree, int x) { // Добавление узла
	if (tree == nullptr) return NewNode(x);
	if (x < tree->field) {
		tree->left = insert(tree->left, x);
	}
	else {
		tree->right = insert(tree->right, x);
	}
	return tree;
}

void FreeTree(BinarTree* tree) { // Очистка дерева
	if (tree != nullptr) {
		FreeTree(tree->left);
		FreeTree(tree->right);
		delete(tree);
	}
}

void TreePrint1(BinarTree* tree) { // префиксная форма обхода дерева
	if (tree != nullptr)
	{
		cout << tree->field << " ";
		TreePrint1(tree->left);
		TreePrint1(tree->right);
	}
}

void TreePrint2(BinarTree* tree) { // постфиксная форма обхода дерева
	if (tree != nullptr)
	{
		TreePrint2(tree->left);
		TreePrint2(tree->right);
		cout << tree->field << " ";
	}
}

void TreePrint3(BinarTree* tree) { // инфиксная форма обхода дерева
	if (tree != nullptr)
	{
		TreePrint3(tree->left);
		cout << tree->field << " ";
		TreePrint3(tree->right);
	}
}

BinarTree* MinValueTree(BinarTree* tree) { // Поиск преемника
	BinarTree* current = tree;
	while (current && current->left != nullptr)
		current = current->left;
	return current;
}

BinarTree* DeleteTree(BinarTree* tree, int key) { // Удаление узла
	if (tree == nullptr) return tree;
	if (key < tree->field)
		tree->left = DeleteTree(tree->left, key);
	else if (key > tree->field)
		tree->right = DeleteTree(tree->right, key);
	else { // Если у узла один дочерний элемент
		if (tree->left == nullptr) {
			BinarTree* tmp = tree->right;
			delete(tree);
			return tmp;
		}
		else if (tree->right = nullptr) {
			BinarTree* tmp = tree->left;
			delete(tree);
			return tmp;
		}
		// Если у узла два дочерних элемента
		BinarTree* tmp = MinValueTree(tree->right);

		// Помещаем префиксного-преемника на место узла, который хотим удалить
		tree->field = tmp->field;

		// Удаляем префиксного-преемника
		tree->right = DeleteTree(tree->right, tmp->field);
	}
}

BinarTree* DeleteElem(BinarTree* tree, int key) {
	BinarTree* parent = nullptr;
	tree = new BinarTree;
}

int main() {
	setlocale(LC_ALL, "Ru");
	BinarTree* tree = nullptr;
	int n, x;
	int key;
	cout << "Сколько элементов хотите добавить ? ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Введите элемент: " << i << "|";
		cin >> x;
		tree = insert(tree, x);
	}
	TreePrint3(tree);

	cout << "Введите номер узла, который хотите удалить" << endl;
	cin >> key;
	DeleteTree(tree, key);
	TreePrint3(tree);

	FreeTree(tree);
	return 0;
}