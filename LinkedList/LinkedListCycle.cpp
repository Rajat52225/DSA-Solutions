/*
Leet Code-141 :- Linked List Cycle.
So for this question i first approached like i stored each node address in a map and checked if it already is there in map and if yes then return 
true else false.
but for this:-
Time Complexity : O(n)
Space Complexity : O(n)

*/

 bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(mp.find(temp)!=mp.end()){
            return true;
            break;
           }
           mp[temp]++;
           temp=temp->next;
        }
        return false;
    }
};

/*
So then i got to know about Floyd's tortoise and hare approach of slow and fast pointer.
1. Its like we take two pointers on head as slow and fast.
2. Slow moves one node at a time and fast as two at a time.
3. when we will traverse it we will simply check that if slow will be equal to fast.
4. If slow will be equal to fast this means a cycle exists else not.

Time Complexity : O(n)
Space Complexity : O(1)

*/
 bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
