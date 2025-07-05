#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    Deque(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int val) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        arr[front] = val;
        cout << "Inserted at front: " << val << "\n";
    }

    void insertRear(int val) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Inserted at rear: " << val << "\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << "\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << "\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n\n";
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.insertRear(30); // should be full now

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    cout << "Front element: " << dq.getFront() << "\n";
    cout << "Rear element: " << dq.getRear() << "\n";

    return 0;
}