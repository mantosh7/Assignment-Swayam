#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    int* arr;
    int size;
    int front;
    int rear;

    MyQueue(int n) {
        arr = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;  
        }

        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;  
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    MyQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70); 

    cout << "Front after dequeue/enqueue: " << q.getFront() << endl;
    cout << "Rear after dequeue/enqueue: " << q.getRear() << endl;

    return 0;
}
