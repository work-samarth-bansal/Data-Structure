#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

class TrieNode {
public:
    std::unordered_map<int, TrieNode*> children;

    TrieNode() {}
};

class Prototype {
private:
    TrieNode* root;

public:
    Prototype() : root(new TrieNode) {}

    ~Prototype() {
        deleteNode(root);
    }

    void insert(int num) {
        TrieNode* current = root;
        int mask = 100000;  // Assuming numbers have at most 6 digits

        while (mask > 0) {
            int digit = num / mask;
            num %= mask;
            mask /= 10;

            if (current->children.find(digit) == current->children.end()) {
                current->children[digit] = new TrieNode;
            }

            current = current->children[digit];
        }
    }

    bool search(int num) {
        TrieNode* current = root;
        int mask = 100000;  // Assuming numbers have at most 6 digits

        while (mask > 0) {
            int digit = num / mask;
            num %= mask;
            mask /= 10;

            if (current->children.find(digit) == current->children.end()) {
                return false;
            }

            current = current->children[digit];
        }

        return true;
    }

    void deleteNode(TrieNode* node) {
        if (node) {
            for (auto& pair : node->children) {
                deleteNode(pair.second);
            }
            delete node;
        }
    }
};

int main() {
    Prototype prototype;

    // Insert numbers into the compact trie
    int numbers[] = {123, 456, 789, 12, 12345, 999};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numCount; ++i) {
        prototype.insert(numbers[i]);
    }

    // Search for numbers in the compact trie
    int searchNumbers[] = {123, 789, 111, 999, 888 , 4};
    int searchCount = sizeof(searchNumbers) / sizeof(searchNumbers[0]);

    for (int i = 0; i < searchCount; ++i) {
        if (prototype.search(searchNumbers[i])) {
            std::cout << searchNumbers[i] << " exists in the compact trie.\n";
        } else {
            std::cout << searchNumbers[i] << " does not exist in the compact trie.\n";
        }
    }


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken by code: " << duration << " microseconds" << std::endl;
}


/*

Pros:
-Uses a custom array-based solution for node storage, potentially reducing memory overhead.
-Efficient for storing integers with a fixed number of digits.
-Simplified logic with fewer conditionals for traversal.

Cons:
-Does not store a marker node, so you need to check for the end of the number differently
(e.g., by checking the absence of children in the last digit node).
-May not be as versatile as the original trie implementation for handling more complex data types or varying input sizes.



Use the Compact Trie Implementation If:
-You are dealing specifically with integers or data types with a fixed number of digits.
-You prefer a simpler, array-based approach with potentially reduced memory overhead.
-You can manage end-of-number checks without a dedicated marker node.

*/