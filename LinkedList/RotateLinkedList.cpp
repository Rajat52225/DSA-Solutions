/*
Leet Code - 61 :- Rotate List
So i approached this like :-
1. Store the nodes in a vector a.
2. Then update k=k%size of a.
3. Then when k>0 do like reverse 0 to k elements, then reverse k to end elements and then reverse whole vector a.
4. Then just push back the list elements to update the linked list.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            return head;
        }
        vector<int>a;
        ListNode*temp=head;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        k=k%a.size();
        if(k>0){
        int l1=0;
        int r1=a.size()-k-1;
        while(l1<r1){
            swap(a[l1],a[r1]);
            l1++;
            r1--;
        }
           int l2=a.size()-k;
        int r2=a.size()-1;
        while(l2<r2){
            swap(a[l2],a[r2]);
            l2++;
            r2--;
        }
        reverse(a.begin(),a.end());
      }
      ListNode*tempx=head;
      for(int i=0;i<a.size() && tempx!=nullptr;i++){
           tempx->val=a[i];
           tempx=tempx->next;
      }
      return head;
    }
};
