#include <iostream>
#include <queue>
#include <stack>
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
	
	//ծառի բարձրություն։ (լայնակի շրջանցում)
	void height_private(Node* root);
	//1 որդի ունեցող հանգույցների քանակը
	//Ռեկուրսիվ
	int one_child_recursive_private(Node* root);

	//2 որդի ունեցող հանգույցների քանակը
	int two_child_recursive_private(Node* a);
	// Ոչ ռեկուրսիվ
	int two_child_interative_private(Node* a);
	
	void preorderTraversal_private(Node* node);
	void postorderTraversal_private(Node* node);
	void inorderTraversal_private(Node* node);


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

	void height(){
		height_private(root);
	}

	int one_child_recursive() {
		return one_child_recursive_private(root);
	}

	int two_child_recursive() {
		return two_child_recursive_private(root);
	}

	int two_child_interative() {
		return two_child_interative_private(root);
	}
	
//////////////////RECURSION TRAVERSAL////////////////////////
	void preorderTraversal() {
		preorderTraversal_private(root);
	}
	void postorderTraversal() {
		postorderTraversal_private(root);
	}
	void inorderTraversal() {
		inorderTraversal_private(root);
	}
//////////////////INTERATIVE TRAVERSAL//////////////////////
	void inOrder_interative(){
		stack<Node*> s;
		Node* curr = root;

		while (curr != NULL || s.empty() == false){

			while (curr != NULL){
				s.push(curr);
				curr = curr->left;
			}

			curr = s.top();
			s.pop();

			cout << curr->data << "->";

			curr = curr->right;

		} 
	}
	void Preorder_iterative(){
		if (root == NULL)
			return;

		stack<Node*> nodeStack;
		nodeStack.push(root);

		/* Pop all items one by one. Do following for every popped item
		   a) print it
		   b) push its right child
		   c) push its left child
		Note that right child is pushed first so that left is processed first */
		while (nodeStack.empty() == false) {
			// Pop the top item from stack and print it
			Node* node = nodeStack.top();
			cout << node->data << "->";
			nodeStack.pop();

			// Push right and left children of the popped node to stack
			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
	}

	void postorder_interative() {
		// If empty return;
		if (root == NULL) return;
		stack <Node*> s1, s2;
		Node* temp = root;
		s1.push(temp);
		// Continue till stack is empty 
		while (!s1.empty()) {
			temp = s1.top();
			s1.pop();
			// Push the top element of first stack
			s2.push(temp);
			// Push the left child of the top element
			if (temp->left != NULL) s1.push(temp->left);
			// Push the right child of the top element
			if (temp->right != NULL) s1.push(temp->right);
		}
		// Print the second stack
		while (!s2.empty()) {
			cout << s2.top()->data << "->";
			s2.pop();
		}
		cout << endl;
	}
};













int main() {
	int dataArr[17] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 1, 70, 87, 80};

	BST tree;

	for (int i : dataArr) {
		tree.insert(i);
	}


	/*tree.print_in_order();
	cout << endl;*/
	/*Node* node = tree.get_node(32);
	cout << node->data;
	*/

	//tree.print_children(tree.get_root_data());
	//cout << tree.find_min();
	/*tree.delete_node(50);
	tree.print_in_order();*/

	//tree.height();
	
	//cout << tree.one_child_recursive();

	/*cout << tree.two_child_interative() << endl;
	cout << tree.two_child_recursive();*/

	tree.inorderTraversal();
	cout << endl;
	tree.preorderTraversal();
	cout << endl;
	tree.postorderTraversal();
	cout << endl;
	tree.inOrder_interative();
	cout << endl;
	tree.Preorder_iterative();
	cout << endl;
	tree.postorder_interative();
	return 0;
}






// Preorder traversal
void BST::preorderTraversal_private(struct Node* node) {
	if (node == NULL)
		return;

	cout << node->data << "->";
	preorderTraversal_private(node->left);
	preorderTraversal_private(node->right);
}

// Postorder traversal
void BST::postorderTraversal_private(struct Node* node) {
	if (node == NULL)
		return;

	postorderTraversal_private(node->left);
	postorderTraversal_private(node->right);
	cout << node->data << "->";
}

// Inorder traversal
void BST::inorderTraversal_private(struct Node* node) {
	if (node == NULL)
		return;

	inorderTraversal_private(node->left);
	cout << node->data << "->";
	inorderTraversal_private(node->right);
}


int BST::two_child_interative_private(Node* node)
{
	int count = 0;
	stack <Node*> my_stack;

	bool b = true;
	while (b)
	{
		while (node != NULL)
		{
			
			if (node->left && node->right) {
				my_stack.push(node);
				count++;
			}
			node = node->left;
		}
		if (my_stack.empty()) b = false;
		else {
			node = my_stack.top();
			my_stack.pop();
			node = node->right;
		}	return count;
	}
}

int BST::two_child_recursive_private(Node* a)
{
	if (a == NULL) return 0;
	int k = 0;
	if (a->left && a->right)
		k = 1; 
	return two_child_recursive_private(a->left) + two_child_recursive_private(a->right) + k;
}


int BST::one_child_recursive_private(Node* root)
{
	if (root == NULL) return 0;
	int k = 0;
	if ((!root->left && root->right) || (root->left && !root->right))
		k = 1; return one_child_recursive_private(root->left) + one_child_recursive_private(root->right) + k;
}

//ծառի բարձրություն։ (լայնակի շրջանցում)
void BST::height_private(Node* root) {

	Node* p = root;
	queue <Node*> A;
	int level = 0, t = 1, k;
	A.push(p);
	while (!A.empty())
	{
		k = 0;
		for (int i = 0; i < t; i++)
		{
			p = A.front(); A.pop();
			if (p->left) { A.push(p->left); k++; }
			if (p->right) { A.push(p->right); k++; }
		}
		level++;
		t = k;
	}
	cout << level;
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