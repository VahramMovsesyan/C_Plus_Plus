#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* left, * right;
    Node(int value) {
        this->value = value;
        left = right = NULL;
    }
};
// harc 3 Ռեկուրսիվ եղ․ բինար ծառի յուրաքանչյուր գագաթում գրանցել, թե լայնակի շրջանցելիս 
// քանի բաց թողած գագաթ կա մինչև այդ գագաթը ծառի արմատից սկսած
void solve(Node* node, int depth) {
    if (node->left == NULL) {
        return;
    }
    node->value = depth;
    solve(node->left, depth + 1);
    solve(node->right, depth + 1);
}
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}
//harc 4 main-ում իրականացնել ծառի կառուցումը։Կազմակերպել վերևում մշակված ֆունկցիայի կանչը։
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Before: ";
    printInorder(root);
    solve(root, 0);
    cout << "\nAfter: ";
    printInorder(root);
    return 0;
}
/*       0   
       /   \
      1     1
    /  \   / \
   2   5  6   7
  / \
 8   9            */