#include <iostream>
#include <list>
#include <chrono>
using namespace std;

class Prototype {
private:
    static const int TABLE_SIZE = 10;
    std::list<int> hashTable[TABLE_SIZE];

    int hashFunction(int num) {
        return num % TABLE_SIZE;
    }

public:
    void insert(int num) {
        int index = hashFunction(num);
        hashTable[index].push_back(num);
    }

    bool search(int num) {
        int index = hashFunction(num);
        for (int val : hashTable[index]) {
            if (val == num) {
                return true;
            }
        }
        return false;
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

Average Case: O(1), assuming a good hash function with minimal collisions.
Best Case: O(1), when the hash function distributes the keys evenly across the buckets and there are no collisions.
Worst Case: O(n), when all keys hash to the same bucket, resulting in a linked list of all keys. In this case, insertion requires iterating through the list, making it linear in the number of elements in the list.


Search Time Complexity:

Average Case: O(1), assuming a good hash function with minimal collisions.
Best Case: O(1), when the hash function and the linked list length in each bucket are both constant.
Worst Case: O(n), when all keys hash to the same bucket and form a long linked list. In this case, searching requires iterating through the list, making it linear in the number of elements in the list.


Space Complexity:

Average Case: O(n + k), where n is the number of stored elements and k is the number of buckets.
Worst Case: O(n + k), when all n elements hash to the same bucket, leading to a long linked list. The space complexity becomes linear in the number of stored elements plus the number of buckets.

*/