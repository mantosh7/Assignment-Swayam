#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

void insert(int x) {
    pq.push(x);
}

void removeMax() {
    if (!pq.empty()) {
        pq.pop();
    }
}

void find(int x) {
    priority_queue<int> temp = pq;
    bool found = false;
    while (!temp.empty()) {
        if (temp.top() == x) {
            found = true;
            break;
        }
        temp.pop();
    }
    if (found)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        string op;
        cin >> op;
        if (op == "Insert") {
            int x;
            cin >> x;
            insert(x);
        } else if (op == "Delete") {
            removeMax();
        } else if (op == "Find") {
            int x;
            cin >> x;
            find(x);
        }
    }
    return 0;
}
