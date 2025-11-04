#include <bits/stdc++.h>
using namespace std;

class myStack {
    int *arr;
    int top;
    int size;

public:
    myStack(int n) {
        size = n;
        arr = new int[n];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (!isFull()) {
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int peek() {
        if (!isEmpty()) return arr[top];
        return -1;
    }
};

int main() {
    int n = 5;
    myStack st(n);

    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element: " << st.peek() << endl;
    st.pop();
    cout << "After pop, top: " << st.peek() << endl;
    cout << "Is empty: " << (st.isEmpty() ? "true" : "false") << endl;
    cout << "Is full: " << (st.isFull() ? "true" : "false") << endl;

    return 0;
}
