/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* nxt = nullptr) : val(x), next(nxt) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if (temp1 == NULL) return list2;
        if (temp2 == NULL) return list1;

        ListNode* head = NULL;
        ListNode* temp = head;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                ListNode* newNode = new ListNode(temp1->val);
                if (head == NULL) {
                    head = newNode;
                    temp = head;
                } else {
                    temp->next = newNode;
                    temp = newNode;
                }
                temp1 = temp1->next;
            } else {
                ListNode* newNode = new ListNode(temp2->val);
                if (head == NULL) {
                    head = newNode;
                    temp = head;
                } else {
                    temp->next = newNode;
                    temp = newNode;
                }
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            ListNode* newNode = new ListNode(temp1->val);
            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            ListNode* newNode = new ListNode(temp2->val);
            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
            temp2 = temp2->next;
        }

        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List2: 1 -> 3 -> 5
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(5);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
