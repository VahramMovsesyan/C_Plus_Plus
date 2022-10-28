#include <iostream>
using namespace std;
class Set {
public:
    Set();
    ~Set();
    int GetSize() {
        return Size;
    }
    void pop_front(int data);
    int& operator[](const int index);
    bool patkanum_E(int value);
    void unique(Set A, Set B);
private:
    class Node {
    public:
        int data;
        Node* pnext;
        Node(int data = int(), Node* pnext = nullptr) {
            this->data = data;
            this->pnext = pnext;
        }
    };
    int Size;
    Node* head;
};
Set::Set() {
    Size = 0;
    head = nullptr;
}
Set::~Set() {
}
void Set::pop_front(int data) {
    head = new Node(data, head);
    Size++;
}
int& Set::operator[](const int index) {
    int counter = 0;
    Node* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pnext;
        counter++;
    }

}
bool Set::patkanum_E(int value) {
    Node* current = head;
    bool temp = false;
    while (current != nullptr) {
        if (current->data == value) {
            temp = true;
            break;
        }
        else {
            current = current->pnext;
        }
    }
    return temp;
}
Set unique(Set A, Set B) {
    if (A.GetSize() == 0 && B.GetSize() == 0) {
        return;
    }
    else {
        Set C;
        int i = 0; int j = 0;
        while (A.GetSize()) {
            for (i = 0; i < A.GetSize(); i++) {
                C.pop_front(A[i]);
            }
        }
        while (B.GetSize()) {
            for (i = 0; i < B.GetSize(); i++) {
                C.pop_front(A[i]);
            }
        }

    }
    return C;
}


int main() {
    cout << "hi" << endl;
    Set lsr;
    lsr.pop_front(1);
    lsr.pop_front(2);
    lsr.pop_front(3);
    lsr.pop_front(3);
    Set lsr2;
    lsr2.pop_front(4);
    lsr2.pop_front(5);
    lsr2.pop_front(6);
    lsr2.pop_front(7);
    cout << lsr.GetSize() << endl;
    cout << lsr.patkanum_E(2) << endl;
    unique(lsr, lsr2);

    return 0;
}