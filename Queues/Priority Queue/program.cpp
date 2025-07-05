#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;  // min-heap

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return heap[0];
    }

    void deleteMin() {
        if (heap.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << "\n\n";
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(50);
    pq.insert(30);
    pq.insert(20);
    pq.insert(10);
    pq.insert(40);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Min: " << pq.getMin() << "\n";

    pq.deleteMin();
    cout << "After deleting min: ";
    pq.display();

    return 0;
}
