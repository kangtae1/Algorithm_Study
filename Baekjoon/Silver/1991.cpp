#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    char name;
    Node *left;
    Node *right;

    explicit Node(char name) {
        this->name = name;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree {
public:
    Node *root;

    Tree() {
        this->root = nullptr;
    }

    void insert(char name, char left, char right) {
        if (this->root == nullptr) {
            this->root = new Node(name);
            if (left != '.') this->root->left = new Node(left);
            if (right != '.') this->root->right = new Node(right);
        } else {
            Node *node = search(this->root, name);
            if (left != '.') node->left = new Node(left);
            if (right != '.') node->right = new Node(right);
        }
    }

    Node *search(Node *node, char name) {
        if (node == nullptr) return nullptr;
        if (node->name == name) return node;

        Node *left = search(node->left, name);
        if (left != nullptr) return left;

        Node *right = search(node->right, name);
        if (right != nullptr) return right;

        return nullptr;
    }

    void preorder (Node *node) {
        if (node == nullptr) return;
        cout << node->name;
        preorder(node->left);
        preorder(node->right);
    }

    void inorder (Node *node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->name;
        inorder(node->right);
    }

    void postorder (Node *node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    Tree tree;
    for (int i = 0; i < n; i++) {
        char name, left, right;
        cin >> name >> left >> right;
        tree.insert(name, left, right);
    }

    tree.preorder(tree.root);
    cout << endl;
    tree.inorder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}