#include <iostream>
using namespace std;

vector<int> levelOrderTraversal(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    return result;
}



vector<int> preOrderTraversal(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        result.push_back(current->data);

        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }

    return result;
}


int main() {
    
    return 0;
}