/*
Leet Code - 206 :- Reverse Linked List.
Here I first approached wuth like take a stack and push each need in it starting from head node and then pop each back which will be in a reverse order so we get
the reversed linked list but it have time and space complexity as O(n) .

So the better approach was iterative approach:
1. We take three pointers prev,temp,pos.
2. We set prev=nullptr and temp as head and pos as next of temp.
3. Then what we did is set next of temp to prev and then prev to temp and temp to pos.
4. This we way we continue until temp==nullptr .
5. We return the prev node then and we gets our reversed singly Linked List.

Time Complexity : O(n).
Space Complexity : O(1).

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prev=nullptr;
      ListNode* temp=head;
      while(temp!=nullptr){
        ListNode* pos=temp->next;
        temp->next=prev;
        prev=temp;
        temp=pos;
      }
      return prev;
    }
};
