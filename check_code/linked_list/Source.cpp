#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;

public:
    List();
    List(int info);
    void insertAtTheFront(int);
    void insertAtTheEnd(int);
    void insertAfterIndex(int, int);
    void printList();
    void deleteAfterIndex(int);
    void deleteAtTheFront();
    void deleteAtTheEnd();
    void deleteDuplicates();
    void deleteWithValue(int);
    void deleteMaxValues();
    void bubbleSort();
};

List::List() {
    this->head = NULL;
};

List::List(int info) {
    Node* new_node = new Node();
    head = new_node;
    new_node->data = info;
    new_node->next = NULL;
};

void List::insertAtTheFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
};

void List::insertAfterIndex(int data, int ind) {
    Node* newNode = new Node();
    newNode->data = data;
    Node* temp = head;
    for (int i = 0; i < ind; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::insertAtTheEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void List::printList() {
    if (head == NULL) cout << "empty list " << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

void List::deleteAtTheFront() {
    Node* temp = head;
    head = head->next;
    delete(temp);
}

void List::deleteAtTheEnd() {
    Node* temp = head;
    Node* prev = head;
    while (temp->next != NULL) {
        prev = prev->next;
        temp = prev->next;
    }
    prev->next = NULL;
}

void List::deleteWithValue(int value) {
    Node* temp = NULL;
    Node* prev = NULL;
    while (head->data == value) {
        temp = head;
        head = head->next;
        temp = NULL;
    }
    temp = head->next;
    prev = head;
    while (temp != NULL) {
        if (temp->data == value) {
            prev->next = temp->next;
            temp = temp->next;
        }
        else {
            prev = prev->next;
            temp = temp->next;
        }

    }
}

void List::deleteAfterIndex(int ind) {
    Node* temp = head;
    if (ind == 0) {
        head = head->next;
        delete(temp);
    }
    for (int i = 0; i < ind; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
};

void List::deleteDuplicates() {
    Node* current = head, * index = NULL, * temp = NULL;

    while (current != NULL) {
        temp = current;
        index = current->next;

        while (index != NULL) {
            if (current->data == index->data) {
                temp->next = index->next;
            }
            else {
                temp = index;
            }
            index = index->next;
        }
        current = current->next;
    }
};

void List::deleteMaxValues() {
    int max = head->data;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    deleteWithValue(max);
}

void List::bubbleSort() {
    Node* first = head;
    Node* second = head->next;
    while (first != NULL) {
        second = first->next;
        while (second != NULL) {
            if (first->data > second->data) {
                swap(first->data, second->data);
            }
            second = second->next;
        }
        first = first->next;
    }
}

int main() {
    List list1(1);
    list1.insertAtTheEnd(2);
    list1.insertAtTheEnd(3);
    list1.insertAtTheFront(0);
    list1.printList();
    

    return 0;
}