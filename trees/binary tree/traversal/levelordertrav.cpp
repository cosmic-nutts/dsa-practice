#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// The levelorder function (as you provided)
vector<int> levelorder(Node* root) {
    queue<Node*> q;
    vector<int> result;
    if (!root) return result;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return result; // <-- Add this line to return the result
}

int main() {
    // Create a simple binary tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Get the level order traversal
    vector<int> traversal = levelorder(root);

    // Print the result
    cout << "Level order traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    // Free memory (not strictly necessary for small programs, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

