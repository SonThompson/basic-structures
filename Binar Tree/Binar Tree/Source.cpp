#include <iostream>
#include <stdlib.h>
constexpr auto MAXFIELD = 100;;
using namespace std;

typedef struct BinarTree {
	int field;
	BinarTree* left;
	BinarTree* right;
}BinarTree;

BinarTree* NewNode(int x) { // �������� ����
	BinarTree* tree = new BinarTree;
	tree->field = x;
	tree->left = nullptr;
	tree->right = nullptr;
	return tree;
}

BinarTree* insert(BinarTree* tree, int x) { // ���������� ����
	if (tree == nullptr) return NewNode(x);
	if (x < tree->field) {
		tree->left = insert(tree->left, x);
	}
	else {
		tree->right = insert(tree->right, x);
	}
	return tree;
}

void FreeTree(BinarTree* tree) { // ������� ������
	if (tree != nullptr) {
		FreeTree(tree->left);
		FreeTree(tree->right);
		delete(tree);
	}
}

void TreePrint1(BinarTree* tree) { // ���������� ����� ������ ������
	if (tree != nullptr)
	{
		cout << tree->field << " ";
		TreePrint1(tree->left);
		TreePrint1(tree->right);
	}
}

void TreePrint2(BinarTree* tree) { // ����������� ����� ������ ������
	if (tree != nullptr)
	{
		TreePrint2(tree->left);
		TreePrint2(tree->right);
		cout << tree->field << " ";
	}
}

void TreePrint3(BinarTree* tree) { // ��������� ����� ������ ������
	if (tree != nullptr)
	{
		TreePrint3(tree->left);
		cout << tree->field << " ";
		TreePrint3(tree->right);
	}
}

BinarTree* MinValueTree(BinarTree* tree) { // ����� ���������
	BinarTree* current = tree;
	while (current && current->left != nullptr)
		current = current->left;
	return current;
}

BinarTree* DeleteTree(BinarTree* tree, int key) { // �������� ����
	if (tree == nullptr) return tree;
	if (key < tree->field)
		tree->left = DeleteTree(tree->left, key);
	else if (key > tree->field)
		tree->right = DeleteTree(tree->right, key);
	else { // ���� � ���� ���� �������� �������
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
		// ���� � ���� ��� �������� ��������
		BinarTree* tmp = MinValueTree(tree->right);

		// �������� �����������-��������� �� ����� ����, ������� ����� �������
		tree->field = tmp->field;

		// ������� �����������-���������
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
	cout << "������� ��������� ������ �������� ? ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "������� �������: " << i << "|";
		cin >> x;
		tree = insert(tree, x);
	}
	TreePrint3(tree);

	cout << "������� ����� ����, ������� ������ �������" << endl;
	cin >> key;
	DeleteTree(tree, key);
	TreePrint3(tree);

	FreeTree(tree);
	return 0;
}