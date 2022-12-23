#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    node* llink;
    node* rlink;
    int data;
    node(int data1) :llink(NULL), rlink(NULL), data(data1) {}
};
class BinaryTree {
private:
    int size;
    node* root;
public:
    BinaryTree() :size(0), root(NULL) {};
    node*& getroot() { return root; }
    int& getsize() { return size; }
    void insert(int elem);
    node* Search(int elem, node* parent);
    void Interactive();
    void iterativeuxix();
};
void BinaryTree::iterativeuxix() {
    if (root == NULL)
        return;
    node* nod = root;
    stack<node*>s;
    s.push(nod);
    while (!s.empty()) {
        cout << s.top()->data << ' ';
        nod = s.top();
        s.pop();
        if (nod->rlink != NULL) {
            s.push(nod->rlink);

        }
        if (nod->llink != NULL) {
            s.push(nod->llink);
        }
    }
    return;


}
void BinaryTree::insert(int elem) {
    node* parent = nullptr;
    node* t = root;
    while (t) {
        if (t->data > elem) {
            parent = t;
            t = t->llink;
        }
        else if (t->data == elem) {
            return;
        }
        else {
            parent = t;
            t = t->rlink;
        }
    }
    node* p = new node(elem);
    if (parent == nullptr) {
        ++size;
        root = p;
        return;
    }if (parent->data > elem) {
        ++size;
        parent->llink = p;
        return;
    }
    else {
        ++size;
        parent->rlink = p;
        return;
    }
};
void BinaryTree::Interactive() {
    stack<node*>s;
    node* nod = root;
    while (!s.empty() || nod != NULL) {
        if (nod != NULL) {
            s.push(nod);
            nod = nod->llink;
        }
        else {
            cout << s.top()->data << ' ';
            if (s.top()->rlink != NULL) {
                nod = s.top()->rlink;
            }
            s.pop();
        }

    }return;
};
//class set {
//private:
//    BinaryTree settree;
//
//public:
//
//    BinaryTree& getset() { return settree; }
//    set(int* a, int n);
//    set miavorum(set& set1);
//};
//set::set(int* a, int n) {
//
//    settree.getroot() = NULL;
//    settree.getsize() = 0;
//    for (int i = 0; i < n; ++i) {
//        settree.insert(a[i]);
//    }
//
//}

int main() {
    BinaryTree c;
    int dataArr_1[] = { 4, 6, 8, 12, 16 };
    int dataArr_2[] = { 2 , 6, 15, 21,45,19,12 };
    for (int i : dataArr_1) {
        c.insert(i);
    }
    for (int j : dataArr_2) {
        c.insert(j);
    }
    c.iterativeuxix();
}