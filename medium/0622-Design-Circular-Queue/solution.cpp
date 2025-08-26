#include <queue>
using namespace std;

class MyCircularQueue {
private:
    queue<int> qu;
    int capacity;

public:
    MyCircularQueue(int k) : capacity(k) {}

    bool enQueue(int value) {
        if (qu.size() == capacity) return false;
        qu.push(value);
        return true;
    }

    bool deQueue() {
        if (qu.empty()) return false;
        qu.pop();
        return true;
    }

    int Front() {
        return qu.empty() ? -1 : qu.front();
    }

    int Rear() {
        return qu.empty() ? -1 : qu.back(); // FIXED: O(1) and non-destructive
    }

    bool isEmpty() {
        return qu.empty();
    }

    bool isFull() {
        return qu.size() == capacity;
    }
};
