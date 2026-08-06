/*
Leet Code - 92 :- Reversing linked list 2.
So approach was like :
just convert to array and then using two pointer reversed the l to r and then reconverted to linked list.

Time Complexity : O(n) .
Space Complexity : O(n) .

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        vector<int>ans;
        ListNode* p=head;
        while(p!=nullptr){
           ans.push_back(p->val);
           p=p->next;
        }
        int i=left-1;
        int j=right-1;
        while(i<j){
           swap(ans[i],ans[j]);
           i++;
           j--;
        }
        ListNode*q=head;
        for(int i=0;i<ans.size();i++){
            q->val=ans[i];
            q=q->next;
        }
        return head;
    }
};
