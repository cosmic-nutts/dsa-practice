#include <iostream>
#include <queue>
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

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n == 0) return 0;

    cout << "Enter root value: ";
    int rootVal;
    cin >> rootVal;
    Node* root = new Node(rootVal);

    queue<Node*> q;
    q.push(root);

    int count = 1;
    while (!q.empty() && count < n) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
            count++;
        }

        if (count >= n) break;

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
            count++;
        }
    }

    // Level order print
    cout << "Level order traversal: ";
    queue<Node*> printQ;
    printQ.push(root);
    while (!printQ.empty()) {
        Node* node = printQ.front();
        printQ.pop();
        cout << node->data << " ";
        if (node->left) printQ.push(node->left);
        if (node->right) printQ.push(node->right);
    }
    cout << endl;

    return 0;
}