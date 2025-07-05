#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue[rear] = val;
        cout << "Enqueued: " << val << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        int val = queue[front];
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Dequeued: " << val << "\n";
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << "\n\n";
    }
};

int main() {
    CircularQueue q(5); // size = 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // should be full now

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60); // wrap-around
    q.enqueue(70); // wrap-around

    q.display();

    return 0;
}
