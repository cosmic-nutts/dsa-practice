
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right; 

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

}

void createBinaryTree(){

}

int main() {

    struct Node* root = new Node(1);
    root->left = new Node(2);   
    root->right = new Node(3);
    root->left->left = new Node(4);
    
    
    return 0;
}



















