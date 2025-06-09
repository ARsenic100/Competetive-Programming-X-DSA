//LinkedList Cycle II
//https://leetcode.com/problems/linked-list-cycle-ii/
// Detect the node where the cycle begins in a linked list
// This code uses Floyd's Cycle Detection Algorithm (Tortoise and Hare algorithm).

#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!= nullptr && fast->next!= nullptr){
            fast= fast->next->next;
            slow = slow->next;

            if(slow==fast){
                ListNode *start= head;
                while(start!= slow){
                    start= start->next;
                    slow= slow->next;
                }
                return slow;
            }

        }
        return nullptr;
    }
};
