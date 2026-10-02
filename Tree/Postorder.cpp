/*
Leet Code-145 :- find postorder traversal of binary tree.

So we have two approaches:-
1. Recursive.
2. Iterative.

#Recursive approach:-
1. We return if node points to nullptr.
2. We apply recursion on node->left.
3. We apply recursion on node->right.
4. We push node->val to ans.
5. We continue like this and finally return the answer.

Postorder traversal is:
Left -> Right -> Root

Time Complexity : O(n).
Space Complexity : O(h).

#Iterative approach:-
1. In this we use two stacks.
2. First we put root in stack1.
3. We run loop until stack1 isn't empty.
4. We pop the top element from stack1 and push it into stack2.
5. We push left and then right of the node into stack1 if not null.
6. Finally, we pop elements from stack2 and put their values into answer.
7. We continue until stack2 is empty and return the answer.

Time Complexity : O(n).
Space Complexity : O(n).
*/


// #Recursive :-

class Solution {
public:
    vector<int> ans;

    void post(TreeNode* node) {
        if(node == nullptr) {
            return;
        }

        post(node->left);
        post(node->right);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return ans;
    }
};


// #Iterative :-

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr) {
            return ans;
        }

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();

            st2.push(node);

            if(node->left) {
                st1.push(node->left);
            }

            if(node->right) {
                st1.push(node->right);
            }
        }

        while(!st2.empty()) {
            TreeNode* node = st2.top();
            st2.pop();

            ans.push_back(node->val);
        }

        return ans;
    }
};
