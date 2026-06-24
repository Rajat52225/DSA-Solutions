/*
Leet Code - Delete the middle of a linked list.
So here i approached like :-
1. Found the middle of linked list using slow and fast pointers.
2. Then i copied the value of next node of middle to middle.
3. Then i connected the middle node to next of next node and deleted the next node whose value we had copied.
4. For edge case we had like list with 0,1,2 nodes for that i used edge cases.
5. Like for no or one element i returned true.
6. For two element one i did like connect next of head directly to nullptr.

Time Complexity: O(n) .
Space Complexity: O(1) .

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
    return nullptr;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow!=nullptr && slow->next!=nullptr){
        slow->val=slow->next->val;
        ListNode*temp=slow->next;
        slow->next=temp->next;
        delete temp;
        }
        else{
            head->next=nullptr;
        }
        return head;
    }
};
