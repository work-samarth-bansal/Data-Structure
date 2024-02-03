#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
using namespace std;

class TrieNode {
public:
    std::unordered_map<int, TrieNode*> children;
    int count; // Count of numbers with the same prefix

    TrieNode() : count(0) {}
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
        while (num != 0) {
            int digit = num % 10;
            if (current->children.find(digit) == current->children.end()) {
                current->children[digit] = new TrieNode;
            }
            current = current->children[digit];
            num /= 10;
            current->count++;
        }
        // Add a marker for the end of the number
        current->children[0] = new TrieNode;
    }

    // Helper function to delete the trie nodes
    void deleteNode(TrieNode* node) {
        if (node) {
            for (auto& pair : node->children) {
                deleteNode(pair.second);
            }
            delete node;
        }
    }

    // Helper function to build a sorted array from the trie
    void buildSortedArray(TrieNode* node, int num, vector<int>& result) {
        if (node->children.find(0) != node->children.end()) {
            // Marker node exists, indicating a number ends here
            for (int i = 0; i < node->count; ++i) {
                result.push_back(num);
            }
        }
        for (auto& pair : node->children) {
            buildSortedArray(pair.second, num * 10 + pair.first, result);
        }
    }

    vector<int> sortNumbers() {
        vector<int> sortedNumbers;
        buildSortedArray(root, 0, sortedNumbers);
        return sortedNumbers;
    }
};

int main() {
    Prototype prototype;

    // Insert numbers into the trie
    int numbers[] = {123, 404, 789, 12, 12345, 999};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numCount; ++i) {
        prototype.insert(numbers[i]);
    }

    // Sort numbers using trie
    vector<int> sortedNumbers = prototype.sortNumbers();

    // Print sorted numbers
    cout << "Sorted numbers: ";
    for (int num : sortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken by code: " << duration << " microseconds" << std::endl;

    return 0;
}
