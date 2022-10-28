#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class IntSequence {
	int size;
	Node* head;
public:
	IntSequence();
	IntSequence(int array[], int arrsize);
	// ~IntSequence();
	// IntSequence(IntSequence& list);
	// IntSequence& operator=(const IntSequence& list);
	void InsertAfter(int item);
	void InsertAt(int position, int item);
	bool IsEmpty();
	void pop();
	void display();

	// ընդհանուր բաժանարարների քանակը
	int func2() {
		int baj_tiv = 1;
		for (int i = 2; i <= head->data; i++) {
			Node* temp = this->head;
			bool flag = true;
			while (temp->next != NULL) {
				if (temp->data % i != 0) {
					flag = false;
					break;
				}
				temp = temp->next;
			}
			if (temp->data % i != 0)
				flag = false;

			if (flag) {
				baj_tiv = i;
			}
		}

		return baj_tiv;
	}

	IntSequence func3() {
		IntSequence temp;

		Node* ptr1, * ptr2, * dup;
		ptr1 = this->head;
		while (ptr1 != NULL && ptr1->next != NULL) {
			ptr2 = ptr1;
			bool contain = false;
			while (ptr2->next != NULL) {
				if (ptr1->data == ptr2->next->data) {
					dup = ptr2->next;
					ptr2->next = ptr2->next->next;
					delete(dup);
					contain = true;
					break;
				}
				else
					ptr2 = ptr2->next;
			}
			if (ptr1->data == ptr2->data) {
				dup = ptr2;
				delete(dup);
				contain = true;
			}


			if (!contain)
				temp.InsertAfter(ptr1->data);
			ptr1 = ptr1->next;
		}
		temp.InsertAfter(ptr1->data);

		return temp;
	}
	
	void func4(int position, int item) {
		if (position >= this->size) {
			this->InsertAfter(item);
		}
		else {
			this->InsertAt(position, item);
		}
	}
};

IntSequence::IntSequence()
{
	head = NULL;
	size = 0;
}

IntSequence::IntSequence(int array[], int arrsize)
{
	
	for (int i = 0; i < arrsize; i++) {
		this->InsertAfter(array[i]);
	}
}
//IntSequence::IntSequence(IntSequence& list){
//	size = 0;
//	Node* temp = list.head;
//	while (temp->next != NULL) {
//		this->InsertAfter(temp->data);
//		temp = temp->next;
//	}
//	this->InsertAfter(temp->data);
//}
void IntSequence::InsertAfter(int item) {
	Node* new_node = new Node();
	new_node->data = item;
	if (head == NULL) {
		head = new_node;
	}
	else {
		Node* ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = new_node;
	}

	size++;
}

void IntSequence::InsertAt(int position, int item){
	if (position<0 || position>this->size)
		cout << "invalid position" << endl;

	Node* new_node = new Node();
	new_node->data = item;

	if (position == 0) {
		new_node->next = head;
		head = new_node;
		size++;
	}
	else {
		Node* ptr = head;
		while (position > 1) {
			ptr = ptr->next;
			--position;
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
		size++;
	}
}

bool IntSequence::IsEmpty(){
	return head == NULL;
}

void IntSequence::pop(){
	if (this->IsEmpty())
		cout << "List is empty" << endl;

	else if (head->next == NULL) {
		cout << "Element Deleted: " << head->data << endl;
		delete (head);
		head = NULL;
	}
	else {
		Node* temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		cout << "Element Deleted: " << temp->next->data << endl;
		delete(temp->next);
		temp->next = NULL;
		size--;
	}
}
;

void IntSequence::display() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;

}


int main() {
	int const SIZE = 4;

	int array[SIZE] = { 4,8,3,12 };
	IntSequence L1(array, SIZE);
	//L1.display();

	IntSequence L2(L1);
	L2.InsertAfter(8);
	L2.InsertAfter(24);
	//cout << L2.func2();

	IntSequence L4;
	L4 = L2.func3();
	L4.display();
	L4.func4(6, 0);
	L4.display();

	return 0;
}
