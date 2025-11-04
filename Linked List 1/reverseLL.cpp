/*
Given the head of a singly linked list, reverse the list, and return the reversed list
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr) {
            slow->next = prev;
            prev = slow;
            slow = fast;
            fast = fast->next;
        }

        slow->next = prev;
        return slow;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
