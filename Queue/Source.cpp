#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front, * rear;
    int size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    Queue(int data) {
        Node* new_node = new Node();
        this->front = new_node;
        this->rear = new_node;
        new_node->data = data;
        new_node->next = NULL;
        size = 0;
        size++;
    }

    int length() {
        return size;
    }

    bool Empty() {
        return !this->length();
    }

    void insertQ(int item) {
        Node* temp = new Node();
        temp->data = item;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            size++;
            return;
        }
        rear->next = temp;
        rear = temp;
        size++;
    }

    void deleteQ() {
        if (front == NULL)
            return;


        Node* temp = front;
        front = front->next;
        delete (temp);
        size--;
    }

    int frontQ() {
        return this->front->data;
    }

    void clearQ() {
        delete(this->front);
        size = 0;
    }

    void mergeQ_reverse(Queue firstQ, Queue secQ) {

        while (firstQ.front) {
            this->insertQ(firstQ.front->data);
            firstQ.front = firstQ.front->next;
        }

        while (secQ.front) {
            this->insertQ(secQ.rear->data);
            if (secQ.rear == secQ.front) break;
            Node* temp = secQ.front;
            while (temp->next->next) {
                temp = temp->next;
            }
            temp->next = NULL;
            secQ.rear = temp;

        }

    }

    void printQ() {
        Node* temp = this->front;
        cout << "Front -> ";
        while (temp) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << " <- Rear" << endl;
    }
};

int main() {

    Queue my_queue;

    my_queue.insertQ(1);
    my_queue.insertQ(2);
    my_queue.insertQ(3);
    my_queue.insertQ(4);

    my_queue.printQ();
    // cout << my_queue.length();
    // cout << my_queue.Empty();

    //my_queue.deleteQ();

    // my_queue.printQ();
    // my_queue.frontQ();
    // my_queue.clearQ();

    Queue oth_queue;

    oth_queue.insertQ(5);
    oth_queue.insertQ(6);
    oth_queue.insertQ(7);
    oth_queue.insertQ(8);

    oth_queue.printQ();

    Queue third;

    third.mergeQ_reverse(my_queue, oth_queue);
    third.printQ();

    return 0;
}