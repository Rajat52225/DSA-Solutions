/*
Leet Code-237:- Delete Node In A Linked List.
So in this question we were given the node which is to be deleted in a singly linked list but not given access to head.
So my approach was like since in a singly linked list we can only move forward and not backward then what i did is:-
1. I copied the value of next node of the node to the node to be deleted .
2. Then i took a pointer to the next node of node to be deleted say temp.
3. Then what i did is i connected the next of copied value one to next of temp.
4. Then i applied delete operation on temp.

Time Complexity - O(1)
Space Complexity - O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      node->val=node->next->val;
      ListNode* temp=node->next;
      node->next=temp->next;
      delete temp;
    }
};
