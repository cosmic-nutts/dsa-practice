#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* binarytree() {
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    }
    Node* temp = new Node(x);
    temp->left = binarytree();
    temp->right = binarytree();
    return temp;
}

// Preorder traversal to display the tree
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cout << "Enter node values in preorder (-1 for NULL): ";
    Node* root = binarytree();
    cout << "Preorder traversal of the created tree: ";
    preorder(root);
    cout << endl;
    return 0;
}