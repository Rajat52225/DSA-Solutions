/*
Leet Code - 328 :- Odd Even LinkedList.
So this question asked to segregate odd indexed nodes together followed by even index ones but space complexity should be O(1).
So the approach followed in this is that:-
1. Take a odd pointer on head and even on next of head and also an evenhead on next of head too.
2. Move odd pointer as connecting odd index to odd only like odd->next=odd->next->next and update odd pointer to odd->next.
3. Move even pointer as connecting even index to even only like even->next=even->next->next and update even pointer to even->next.
4. Then just connect necxt of odd to evenhead and return head;

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
      ListNode*odd=head;
      ListNode*even=head->next;
      ListNode*evenhead=head->next;
      while(even && even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
      }
      odd->next=evenhead;
      return head;
    }
};
