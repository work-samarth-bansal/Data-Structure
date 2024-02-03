#include <iostream>
#include <queue>

// Node structure for the binary heap
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Class representing the binary heap
class BinaryHeap {
private:
    Node* root;

    // Helper function to insert a node into the binary heap
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return createNode(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    // Helper function to find the minimum element node in the binary heap
    Node* findMin(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }

    // Helper function to delete the minimum element from the binary heap
    Node* deleteMin(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* temp = root;
        Node* minNode = findMin(root);

        // Replace the data of the root with the minimum element
        temp->data = minNode->data;

        // Delete the minimum element from the left subtree
        temp->left = deleteMin(temp->left);

        return temp;
    }

    // Helper function to perform in-order traversal and display the elements
    void displayInOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        displayInOrder(root->left);
        std::cout << root->data << " ";
        displayInOrder(root->right);
    }

public:
    // Constructor
    BinaryHeap() : root(nullptr) {}

    // Function to insert a new element into the binary heap
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to delete the minimum element from the binary heap
    void deleteMin() {
        root = deleteMin(root);
    }

    // Function to display the elements of the binary heap
    void display() {
        displayInOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryHeap binaryHeap;
    binaryHeap.insert(3);
    binaryHeap.insert(5);
    binaryHeap.insert(1);

    // Binary heap elements: 3, 5, 1
    
    //binaryHeap.deleteMin();

    std::cout << "Binary heap elements: ";
    binaryHeap.display();

    // After deleting the minimum element (1), the binary heap becomes: 3, 5
    return 0;
}
