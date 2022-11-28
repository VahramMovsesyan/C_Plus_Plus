#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node() {
		data = NULL;
		left = right = NULL;
	}
	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

class BST {
	Node* root;

	void insert_private(int data, Node* ptr);
	void print_in_order_private(Node* ptr);
	Node* get_node_private(int key, Node* ptr);
	int find_min_private(Node* ptr);
	void delete_node_private(int key, Node* ptr);
	void remove_match(Node* parent, Node* match, bool left); // left = true, եթե match-ը parent-ի ձախ ճյուղն է 

public:
	BST() {
		root = NULL;
	}

	BST(int item) {
		root = new Node(item);
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

	Node* get_node(int key) {
		return get_node_private(key, root);
	}

	int get_root_data() {
		return root != NULL ? root->data : -1000;
	}

	void print_children(int key) {
		Node* ptr = get_node(key);

		if (ptr != NULL) {
			cout << "Parent Node = " << ptr->data << endl;
			
			ptr->left == NULL ?
				cout << "Left child = NULL\n" :
				cout << "Left child = " << ptr->left->data << endl;
			
			ptr->right == NULL ?
				cout << "Right child = NULL\n" :
				cout << "Right child = " << ptr->right->data << endl;
		}
		else {
			cout << "Key " << key << " is not in the tree" << endl;
		}
	}

	int find_min() {
		return find_min_private(root);
	}

	void delete_node(int key) {
		delete_node_private(key, root);
	}
};


int main() {
	int dataArr[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	
	BST tree;

	for (int i : dataArr) {
		tree.insert(i);
	}

	
	tree.print_in_order();
	cout << endl;
	/*Node* node = tree.get_node(32);
	cout << node->data;
	*/

	//tree.print_children(tree.get_root_data());
	//cout << tree.find_min();
	tree.delete_node(50);
	tree.print_in_order();
	return 0;
}





void BST::remove_match(Node* parent, Node* match, bool left) {
	if (root != NULL) {
		Node* temp;
		int match_data = match->data;
		int min_of_right;

		// ճյուղ(երեխա) չկա
		if (match->left == NULL && match->right == NULL) {
			temp = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete temp;
			cout << "The node containing data " << match_data << " was removed" << endl;
		}
		
		// երբ ջնջվող node-ը ունի 1 ճյուղ(երեխա)

		// երբ այդ ճյուղը աջ ճյուղն է
		else if (match->left == NULL && match->right != NULL) {
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delete match;
			cout << "The node containing data " << match_data << " was removed" << endl;
		}

		// երբ այդ ճյուղը ձախ ճյուղն է
		else if (match->left != NULL && match->right == NULL) {
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delete match;
			cout << "The node containing data " << match_data << " was removed" << endl;
		}

		// երբ ջնջվող node-ը ունի 2 ճյուղ(երեխա)
		else {
			min_of_right = find_min_private(match->right);
			delete_node_private(min_of_right, match);
			match->data = min_of_right;
		}
	}
	else
		cout << "The tree is empty" << endl;
}

void BST::delete_node_private(int key, Node* ptr) {
	if (root != NULL) {

		// ջնջում ենք root-ը
		if (root->data == key) {
			Node* temp = root;
			int root_data = root->data;
			int min_of_right;

			// երբ root-ը չունի ճյուղ(երեխա)
			if (root->left == NULL && root->right == NULL) {
				root = NULL;
				delete temp;
			}

			// երբ root-ը ունի 1 ճյուղ(երեխա)
			else if (root->left == NULL && root->right != NULL) {
				root = root->right;
				temp->right = NULL;
				delete temp;
				cout << "The root node with key " << root_data << " was deleted.\n"
					<< "The new root contains data " << root->data << endl;
			}
			else if (root->left != NULL && root->right == NULL) {
				root = root->left;
				temp->left = NULL;
				delete temp;
				cout << "The root node with key " << root_data << " was deleted.\n"
					<< "The new root contains data " << root->data << endl;
			}

			// երբ root-ը ունի 2 ճյուղ(երեխա)
			else {
				min_of_right = find_min_private(root->right);
				delete_node_private(min_of_right, root);
				root->data = min_of_right;
				cout << "The root data changed successfully.\n new root data is " << root->data << endl;
			}
		}
		/*else {
			if (key < parent->key && parent->left != NULL) {
				parent->left->data == key ?
					remuve_match(parent, parent->left, true) :
					delete_node_private(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL) {
				parent->right->data == key ?
					remuve_match(parent, parent->right, false) :
					delete_node_private(key, parent->right);
			}
			else
				cout << "The data " << key << " was not found in the tree!!!\n";
		}*/
	}
	else
		cout << "The tree is empty\n";
}

int BST::find_min_private(Node* ptr){

	if (root == NULL) {
		cout << "Tree is empty" << endl;
		return -1000;
	}
	else {
		if (ptr->left != NULL)
			return find_min_private(ptr->left);
		else
			return ptr->data;
	}
}


Node* BST::get_node_private(int key, Node* ptr) {
	if (ptr != NULL) {
		if (ptr->data == key)
			return ptr;
		else {
			if (key < ptr->data)
				return get_node_private(key, ptr->left);
			else
				return get_node_private(key, ptr->right);
		}

	}
	else
		return NULL;
}


void BST::print_in_order_private(Node* ptr) {
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


void BST::insert_private(int data, Node* ptr) {
	if (root == NULL) {
		root = new Node(data);
	}
	else if (data < ptr->data) {
		if (ptr->left != NULL)
			insert_private(data, ptr->left);
		else
			ptr->left = new Node(data);
	}
	else if (data > ptr->data) {
		if (ptr->right != NULL)
			insert_private(data, ptr->right);
		else
			ptr->right = new Node(data);
	}
	else
		cout << "The item " << data << " has already been added to the tree" << endl;
}