/*
Leet Code - 148 :- Sort List.
So in this we had to sort the linked list .
My approach was like:-
1. I took a vector and stored nodes values in it.
2. Then i sorted the vector.
3. Then i put back values in linked list and replaced it's values with values of vector.

Time Complexity : O(n logn).
Spac Complexity : O(n).

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
    ListNode* sortList(ListNode* head) {
        vector<int>x;
        ListNode*temp=head;
        while(temp){
            x.push_back(temp->val);
            temp=temp->next;
        }
        sort(x.begin(),x.end());
        ListNode*z=head;
        int i=0;
        while(z && i<x.size()){
              z->val = x[i];
              z = z->next;
              i++;
        }
        return head;
    }
};
