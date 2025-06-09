//Palindrome LinkedList
// https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Find middle using slow-fast pointer
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* head2 = reverseList(slow);

        // Compare first half and reversed second half
        ListNode* p1 = head;
        ListNode* p2 = head2;

        while (p2 != nullptr) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }

    
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr != nullptr) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr;       // Move pointers one position ahead
            curr = next;
        }

        return prev; // prev will be the new head of the reversed list
    }
};