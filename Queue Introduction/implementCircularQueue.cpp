#include <iostream>
using namespace std;

class MyCircularQueue {
public:
    int* arr;
    int size, front, rear;

    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size; 
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size; 
        }
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((rear + 1) % size) == front; 
    }
};

int main() {
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    MyCircularQueue q(n);
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Check Empty\n6. Check Full\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                if (q.enQueue(value))
                    cout << "Enqueued " << value << endl;
                else
                    cout << "Queue is Full!" << endl;
                break;

            case 2:
                if (q.deQueue())
                    cout << "Dequeued successfully." << endl;
                else
                    cout << "Queue is Empty!" << endl;
                break;

            case 3:
                cout << "Front Element: " << q.Front() << endl;
                break;

            case 4:
                cout << "Rear Element: " << q.Rear() << endl;
                break;

            case 5:
                cout << (q.isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
                break;

            case 6:
                cout << (q.isFull() ? "Queue is Full" : "Queue is Not Full") << endl;
                break;

            case 7:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
