#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Function to print the left view of the binary tree
    void leftView() {
        if (root == nullptr)
            return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            bool isFirstNode = true;

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();

                if (isFirstNode) {
                    std::cout << current->data << " ";
                    isFirstNode = false;
                }

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }
    }

private:
    Node* root;
};

int main() {
    BinaryTree tree;

    // Insert some values into the binary tree
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    // Print the left view of the binary tree
    tree.leftView();

    return 0;
}
