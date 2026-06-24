/*
Leet Code - 234 :- Check if given linked list is Palindrome or not.

So first i was thinking like reversing the whole linked list and then compare with original but that didn't pass all test cases because it said it destroys original order of linked list.
So then i follow this approach:
1. First find the middle of linked list through floyd's slow and fast pointer method.
2. Then reverse the remaining half from middle to end.
3. Then compare the first hald and second half if they are equal then list is palindrome else it's not.

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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next && fast->next->next){
              slow=slow->next;
              fast=fast->next->next;
        }
        ListNode*prev=nullptr;
        ListNode*temp=slow;
        while(temp){
            ListNode*pos=temp->next;
            temp->next=prev;
            prev=temp;
            temp=pos;
        }
        ListNode*p1=head;
        ListNode*p2=prev;
        while(p1){
            if(p1->val!=p2->val){
                return false;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};
