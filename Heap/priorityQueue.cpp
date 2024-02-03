#include <iostream>
#include <vector>
using namespace std;

class MaxBinaryHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1; // Return a sentinel value indicating an error
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxElement;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxBinaryHeap pq;

    pq.extractMax();

    pq.insert(10);
    pq.insert(5);
    pq.insert(8);
    pq.insert(15);
    pq.insert(3);

    cout << "Priority Queue: ";
    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
