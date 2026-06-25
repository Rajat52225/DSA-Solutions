/*
Leet Code - 19 :- Delete Nth Node from end of Linked List.
So In this Question we had to delete the nth node from the end.
Approach was like:-
1. Count the length of linked list and subtract the n given.
2. What we got is actually the position next to which is the node which is to be deleted.
3. Then just traverse until we reach the difference we got and connect it to next of its next and delete its next.
4. This is how we deleted the nth node from end of a linked list.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            delete head;
            return nullptr;
        }
        ListNode*temp=head;
        int length=0;
        while(temp){
          length++;
          temp=temp->next;
        }
        int x=length-n;
        ListNode*t=head;
        if(x==0){
            ListNode*del=head;
            head=head->next;
            delete del;
            return head;
        }
        for(int i=0;i<x;i++){
            if(i==(x-1)){
                ListNode*xx=t->next;
                t->next=xx->next;
                delete xx;
                break;
            }
            else{
            t=t->next;
            }
        }
        return head;
    }
};
