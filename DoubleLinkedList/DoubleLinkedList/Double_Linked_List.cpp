#include <iostream>
using namespace std;

struct Node {
	int data;

	Node* next, * prev;
};

class DoubleLinkedList {
	int size;
	Node* head;

public:
	DoubleLinkedList() {
		head = NULL;
		size = 0;
	}

    // exercise 17
    void insert_end(int value){
        if (head == NULL) {
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = new_node->prev = new_node;
            head = new_node;
        }
        else {
            Node* last = head->prev;
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = head;
            head->prev = new_node;
            new_node->prev = last;
            last->next = new_node;

        }

        size++;
    }

    // exercise 17
    void insert_start(int value) {
        if (head == NULL) {
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = new_node->prev = new_node;
            head = new_node;
        }
        else {
            Node* last = head->prev;

            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = head;
            new_node->prev = last;

            last->next = head->prev = new_node;

            head = new_node;
        }
        size++;
    }

    // exercise 18
    void delete_node(int key) {
        if (head == NULL) {
            cout << "list is empty!" << endl;
            return;
        }

        if (head->data == key && head->next == head){
            free(head);
            head = NULL;
            return;
        }

        Node* last = head;

        if (head->data == key){
            while (last->next != head)
                last = last->next;

            last->next = head->next;
            free(head);
            head = last->next;
            return;
        }

        while (last->next != head && last->next->data != key){
            last = last->next;
        }

        Node* d = new Node;
        if (last->next->data == key){
            d = last->next;
            last->next = d->next;
            free(d);
        }
        else
            cout << "no such keyfound";
    }

    void printList(){
        Node* temp = head;
        if (head != NULL) {
            while (temp->next != head) {
                cout << temp->data << "->";
                temp = temp->next;
            };
            cout << temp->data;
        }

        cout << endl;
    }
};

int main() {

    DoubleLinkedList list;

    list.insert_start(0);
    list.insert_start(1);
    list.printList();

    cout << endl << "------------------------------" << endl;

    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.printList();

    cout << endl << "------------------------------" << endl;

    list.delete_node(1);
    list.printList();

	return 0;
}