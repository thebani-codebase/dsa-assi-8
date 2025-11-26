/*
Name: Bani
Roll No: 102403190
Question 6: Implement priority queue using heaps
*/

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    
    int extractMax() {
        if (heap.empty()) {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        
        int maxVal = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return maxVal;
    }
    
    int getMax() {
        if (heap.empty()) {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }
    
    bool isEmpty() {
        return heap.empty();
    }
    
    int size() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;
    
    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.insert(5);
    pq.insert(50);
    
    cout << "Maximum element: " << pq.getMax() << endl;
    cout << "Extracted: " << pq.extractMax() << endl;
    cout << "Extracted: " << pq.extractMax() << endl;
    cout << "Maximum element: " << pq.getMax() << endl;
    
    return 0;
}
