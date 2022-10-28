#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* link;  
};

class List {
private:	
	Node* first;
	int size;
public:

	List() {
		this->size = 0;
		this->first = NULL;
	};

	List(List& my_list) {
		this->size = 0;
		Node* temp = my_list.first;
		while (temp->link != NULL) {
			this->InsertAfter(temp->info);
			temp = temp->link;
		}
		
	};

	List(Node* my_node) {
		this->size = 0;
		Node* temp = my_node;
		while (temp->link != NULL) {
			this->InsertAfter(temp->info);
			temp = temp->link;
		}

	};

	List() {
		this->size = 0;
		Node* temp = first_list.first;
		while (temp->link != NULL) {
			this->InsertAfter(temp->info);
			temp = temp->link;
		}
		temp = second_list.first;
		while (temp->link != NULL) {
			this->InsertAfter(temp->info);
			temp = temp->link;
		}

	};

	~List() {
		Node* current = first;
		while (current != NULL) {
				Node* temp = current;
				current = current->link;
				delete temp;
			}
		size = 0;
	};

	void InsertAfter(int item) {
		Node* new_node = new Node();
		new_node->info = item;
		if (first == NULL) {
			first = new_node;
		}
		else {
			Node* ptr = first;
			while (ptr->link != NULL)
				ptr = ptr->link;

			ptr->link = new_node;
		}

		size++;
	};
	void InsertAfter(Node* item) {
		Node* new_node = item;
		new_node->info = item->info;
		if (first == NULL) {
			first = new_node;
		}
		else {
			Node* ptr = first;
			while (ptr->link != NULL)
				ptr = ptr->link;

			ptr->link = new_node;
		}

		size++;
	};
	

	void InsertAt(int position, int item) {
		if (position<0 || position>this->GetLength())
			cout << "invalid position" << endl;
		
		Node* new_node = new Node();
		new_node->info = item;

		if (position == 0) {
			new_node->link = first;
			first = new_node;
			size++;
		}
		else {
			Node* ptr = first;
			while (position > 1) {
				ptr = ptr->link;
				--position;
			}
			new_node->link = ptr->link;
			ptr->link = new_node;
			size++;
		}
	};

	void DeleteAfter() {
		if (IsEmpty())
			cout << "List is empty" << endl;

		else if (first->link == NULL) {
			cout << "Element Deleted: " << first->info << endl;
			delete (first);
			first = NULL;
		}
		else {
			Node* temp = first;
			while (temp->link->link != NULL) {
				temp = temp->link;
			}
			cout << "Element Deleted: " << temp->link->info << endl;
			delete(temp->link);
			temp->link = NULL;
			size--;
		}
	};

	void DeleteAt(int n) {
		if (n<0 || n>GetLength())
			cout << "invalid position" << endl;
		if (n == 0 && GetLength() != 0) {
			Node* deleted_node = first;
			first = first->link;
			delete deleted_node;

			size--;
		}

		Node* current_node = this->first;
		for (int i = 0; i < n - 1; i++)
			current_node = current_node->link;
		DeleteAfter();

	};

	int& GetData(int position) {
		if (position<0 || position>GetLength())
			cout << "invalid position" << endl;

		Node* ptr = first;
		while (position >= 1) {
			ptr = ptr->link;
			--position;
		}
		return ptr->info;
	};

	int GetLength() {
		return this->size;
	};

	bool IsEmpty() {
		return first == NULL;
	};

	void display() {
		Node* temp = first;
		while (temp != NULL) {
			cout << temp->info << "->";
			temp = temp->link;
		}
		cout << "NULL" << endl;
	}

	// exercise 8 
	void removeDuplicates() {
		Node* ptr1, * ptr2, * dup;
		ptr1 = first;
		while (ptr1 != NULL && ptr1->link != NULL) {
			ptr2 = ptr1;

			while (ptr2->link != NULL) {
				if (ptr1->info == ptr2->link->info) {
					dup = ptr2->link;
					ptr2->link = ptr2->link->link;
					delete(dup);
				}
				else
					ptr2 = ptr2->link;
			}
			ptr1 = ptr1->link;
		}
	}

	Node* Get_first() {
		return this->first;
	}

	// exercise 14
	void merge(List& first_list, List& second_list) {
		Node* firstRef = first_list.Get_first();
		while (firstRef->link != NULL) {
			this->InsertAfter(firstRef->info);
			firstRef = firstRef->link;
		}
		this->InsertAfter(firstRef->info);

		Node* secRef = second_list.Get_first();
		while (secRef->link != NULL) {
			this->InsertAfter(secRef->info);
			secRef = secRef->link;
		}
		this->InsertAfter(secRef->info);

		//mixed_list.display();
	}

};

// exercise 15
bool isPresent(Node* list_pointer, Node* sub_pointer){
	Node* curr1 = list_pointer, * curr2 = sub_pointer;
	if (list_pointer == NULL && sub_pointer == NULL)
		return true;

	if (sub_pointer == NULL || (sub_pointer != NULL && list_pointer == NULL))
		return false;

	while (curr1 != NULL){

		while (curr2 != NULL){
			if (curr1 == NULL)
				return false;

			else if (curr2->info == curr1->info)
			{
				curr2 = curr2->link;
				curr1 = curr1->link;
			}

			else
				break;
		}
		if (curr2 == NULL)
			return true;

		curr2 = sub_pointer;
		list_pointer = list_pointer->link;
	}

	return false;
}


int main() {
	List MyList;

	MyList.InsertAfter(1);
	MyList.InsertAfter(2);
	MyList.InsertAfter(3);
	MyList.InsertAfter(4);
	MyList.InsertAfter(5);
	MyList.InsertAfter(6);
	// MyList.InsertAt(2, 10);
	// cout << MyList.GetLength() << endl;
	MyList.display();

	//MyList.removeDuplicates();
	//MyList.display();
	
	// cout << MyList.GetData(1) << endl;
	// MyList.DeleteAt(0);
	// MyList.display();

	
	List SecList;

	SecList.InsertAfter(2);
	SecList.InsertAfter(3);
	SecList.InsertAfter(4);
	//SecList.InsertAfter(10);
	SecList.display();
	
	cout << isPresent(MyList.Get_first(), SecList.Get_first()) << endl;
	/*

	List Third;
	Third.merge(MyList, SecList);
	Third.display();

	//cout << isPresent(MyList.Get_first(), SecList.Get_first());
	*/

	return 0;
}