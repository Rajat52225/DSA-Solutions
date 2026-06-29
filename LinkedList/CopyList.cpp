/*
Leet Code - 138 :- Copy List with random pointer.
So this i approached like:-
1. Just store like the original node and a copy of it in a hash map.
2. Then create a dummy list and keep a pointer on its head.
3. Keep connecting the next and random of copies to that pointer we get the copied list.
4. Just return value of head from map.

Time Complexity: O(n) .
Space Complexity: O(n) .

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        while(temp){
            Node*newnode=new Node(temp->val);
            mp[temp]=newnode;
            temp=temp->next;
        }
        Node*dummy=new Node(0);
        Node*tempo=dummy;
        temp=head;
        while(temp){
            tempo=mp[temp];
            tempo->next=mp[temp->next];
            tempo->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};
