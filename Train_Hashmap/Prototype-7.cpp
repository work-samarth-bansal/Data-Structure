#include <iostream>
#include <list>

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

    // Insert numbers into the custom hash table
    int numbers[] = {123, 456, 789, 12, 12345, 999};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < numCount; ++i) {
        prototype.insert(numbers[i]);
    }

    // Search for numbers in the custom hash table
    int searchNumbers[] = {123, 789, 111, 999, 888 ,9 ,3, 89};
    int searchCount = sizeof(searchNumbers) / sizeof(searchNumbers[0]);

    for (int i = 0; i < searchCount; ++i) {
        if (prototype.search(searchNumbers[i])) {
            std::cout << searchNumbers[i] << " exists in the hash table.\n";
        } else {
            std::cout << searchNumbers[i] << " does not exist in the hash table.\n";
        }
    }

    return 0;
}
