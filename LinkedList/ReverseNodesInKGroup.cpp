/*
Leet Code - 25(Hard) :- Reverse nodes of a linked list in k groups.
So in this i approached like:-
1. Stored the linked list in a vector.
2. Then i pushed k sized groups in a new vector b and reversed them and pushed them back in a new vector c.
3. If some elements were left which can't be grouped to k size then i pushed them directly to the vector c.
4. Then i updated values from vector c to Linked List and returned head.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>a;
        ListNode*temp=head;
        while(temp!=nullptr){
            a.push_back(temp->val);
            temp=temp->next;
        }
       vector<int> b;
vector<int> c;

for (int i = 0; i < a.size(); i += k) {
    if (i + k <= a.size()) {
        b.clear();

        for (int j = i; j < i + k; j++) {
            b.push_back(a[j]);
        }

        reverse(b.begin(), b.end());

        for (int x : b) {
            c.push_back(x);
        }
    }
    else {
        for (int j = i; j < a.size(); j++) {
            c.push_back(a[j]);
        }
    }
}
       ListNode* tempx = head;

for(int i = 0; i < c.size() && tempx != nullptr; i++) {
    tempx->val = c[i];
    tempx = tempx->next;
}

return head;
    }
};
