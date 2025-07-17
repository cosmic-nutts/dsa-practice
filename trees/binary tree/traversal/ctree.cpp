#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a binary tree from an array (level order, -1 means NULL)
Node* createBinaryTree(const int arr[], int n) {
    if (n == 0 || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* current = q.front();
        q.pop();

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Function to display the binary tree (level order)
void displayLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

int main() {
    int arr[] = {1,2,-1,4,5,6,-1,-1,-1,3,-1,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = createBinaryTree(arr, n);

    cout << "Level order traversal of the created binary tree:" << endl;
    displayLevelOrder(root);

    return 0;
}