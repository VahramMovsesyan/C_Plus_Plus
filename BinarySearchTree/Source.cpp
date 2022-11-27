#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
};

class BST {
	Node* root;


	Node* create_node(int data) {
		Node* node = new Node();
		node->data = data;
		node->left = node->right = NULL;

		return node;
	}


	void insert_private(int data,Node* ptr) {
		if (root == NULL) {
			root = create_node(data);
		}
		else if (data < ptr->data) {
			if (ptr->left != NULL)
				insert_private(data, ptr->left);
			else
				ptr->left = create_node(data);
		}
		else if (data > ptr->data) {
			if (ptr->right != NULL)
				insert_private(data, ptr->right);
			else
				ptr->right = create_node(data);
		}
		else
			cout << "The item " << data << " has already been added to the tree" << endl;
	}


	void print_in_order_private(Node* ptr) {
		if (root != NULL) {
			if (ptr->left != NULL) {
				print_in_order_private(ptr->left);
			}
			cout << ptr->data << " ";
			if (ptr->right != NULL) {
				print_in_order_private(ptr->right);
			}

		}
		else {
			cout << "The tree is empty\n";
		}
	}

public:
	BST() {
		root = NULL;
	}
	BST(int item) {
		Node* temp = new Node();
		temp->data = item;
		temp->left = temp->right = NULL;
		root = temp;
	}
	bool isEmpty() {
		return (root == NULL);
	}

	void insert(int data) {
		insert_private(data, root);
	}
	void print_in_order(){
		print_in_order_private(root);
	}
	
};

int main() {
	int dataArr[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	
	BST tree;

	for (int i : dataArr) {
		tree.insert(i);
	}

	tree.print_in_order();

	return 0;
}