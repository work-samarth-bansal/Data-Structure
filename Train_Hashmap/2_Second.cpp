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
        while (num != 0) {
            int digit = num % 10;
            if (current->children.find(digit) == current->children.end()) {
                current->children[digit] = new TrieNode;
            }
            current = current->children[digit];
            num /= 10;
        }
        // Add a marker for the end of the number
        current->children[0] = new TrieNode;
    }

    bool search(int num) {
        TrieNode* current = root;
        while (num != 0) {
            int digit = num % 10;
            if (current->children.find(digit) == current->children.end()) {
                return false;
            }
            current = current->children[digit];
            num /= 10;
        }
        // Check if the number ends here (marker node exists)
        return current->children.find(0) != current->children.end();
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

    // Insert numbers into the trie
    int numbers[] = {123, 404, 789, 12, 12345, 999};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numCount; ++i) {
        prototype.insert(numbers[i]);
    }

    // Search for numbers in the trie
    int searchNumbers[] = {123, 789, 111, 999, 9 , 4, 23, 404};
    int searchCount = sizeof(searchNumbers) / sizeof(searchNumbers[0]);

    for (int i = 0; i < searchCount; ++i) {
        if (prototype.search(searchNumbers[i])) {
            std::cout << searchNumbers[i] << " exists in the trie.\n";
        } else {
            std::cout << searchNumbers[i] << " does not exist in the trie.\n";
        }
    }


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken by code: " << duration << " microseconds" << std::endl;
}


/*

Insertion Time Complexity:

Average Case: O(d), where d is the average length of the numbers being inserted. This assumes that the length of the numbers is constant.
Best Case: O(1), when there are no shared prefixes among the inserted numbers, and the length of the numbers is constant.
Worst Case: O(d), where d is the length of the longest number being inserted. If all numbers have a common prefix and differ only in their last digit, inserting them would require traversing the entire length of the longest number.


Search Time Complexity:

Average Case: O(d), where d is the average length of the numbers being searched. This assumes that the length of the numbers is constant.
Best Case: O(1), when the target number is found at the first level of the trie.
Worst Case: O(d), where d is the length of the target number being searched. If the target number is present and is at the maximum depth of the trie, searching would require traversing the entire length of the target number.


Space Complexity:

Average Case: O(n * d), where n is the number of stored integers and d is the average length of the integers. This represents the space needed to store the trie nodes and their relationships.
Worst Case: O(n * d), where n is the number of stored integers and d is the length of the longest integer. In the worst case, all integers have distinct prefixes, requiring nodes for each digit in every number.

///////////

Pros:
-Stores a marker node to indicate the end of a number, allowing for precise search.
-Suitable for handling sparse data where numbers have common prefixes.
-Can be adapted for more complex data types beyond integers.

Cons:
-Uses std::unordered_map, which may have higher memory overhead compared to a custom array-based solution.
-Requires memory allocation for each node, leading to potential fragmentation and memory overhead.


Use the Original Trie Implementation If:
-Your use case involves more complex data types beyond integers.
-Numbers have varying lengths, and you need a marker node to indicate the end of each number.
-Memory overhead due to std::unordered_map is acceptable for your application.

*/