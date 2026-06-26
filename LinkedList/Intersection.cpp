/*
Leet Code - 160 :- Find the Intersection of Linked Lists.
So in this question we have to find the intersection node at which the two Linked Lists are merging.
I first Approaches it as i stored pointer to all the nodes of list one in a set and then i checked for nodes of list 2 in set the one which exist first is our intersection node.

Time Complexity : O(m+n) [where m is length of list1 and n is length of list2] .
Space Complexity : O(n) .

But the more optimal approach was like:-
1. Take two pointers temp1 and temp2 on each list head.
2. Now traverse both the lists when the pointer of a list reaches nullptr then we move it to head of second list this way both lists traverse equal steps.
3. We traverse this way until temp1 is equal to temp2 and when this happens means we have actually found our intersection point.
4. Just return any temp1 or temp2 because both pointing at same node.

Time Complexity : O(m+n) .
Space Complexity : O(1) .

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode*temp1=headA;
    //     ListNode*temp2=headB;
    //    unordered_set<ListNode*>mp;
    //    while(temp1!=nullptr){
    //     mp.insert(temp1);
    //     temp1=temp1->next;
    //    }
    //    while(temp2!=nullptr){
    //     if(mp.find(temp2)!=mp.end()){
    //         return temp2;
    //         break;
    //     }
    //     temp2=temp2->next;
    //    }
    //    return nullptr;
    ListNode*temp1=headA;
    ListNode*temp2=headB;
    while(temp1!=temp2){
        temp1=(temp1==nullptr)?headB:temp1->next;
        temp2=(temp2==nullptr)?headA:temp2->next;
    }
     return temp1;
    }
};
