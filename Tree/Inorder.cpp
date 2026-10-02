/*
Leet Code-94 :- find inorder traversal of binary tree.

So we have two approaches:-
1. Recursive.
2. Iterative.

#Recursive approach:-
1. We return if node points to nullptr.
2. We apply recursion on node->left.
3. We push node->val to ans.
4. We apply recursion on node->right.
5. We continue like this and finally return the answer.

Inorder traversal is:
Left -> Root -> Right

Time Complexity : O(n).
Space Complexity : O(h).

#Iterative approach:-
1. In this we use a stack.
2. We start from root.
3. We keep pushing the left nodes into the stack until node becomes nullptr.
4. Then we take the top node from stack and put its value into answer.
5. We pop that node.
6. Then we move to its right subtree.
7. We continue this until both node is nullptr and stack is empty.
8. Finally we return the answer.

Time Complexity : O(n).
Space Complexity : O(h).
*/


// #Recursive :-

class Solution {
public:
    vector<int> ans;

    void in(TreeNode* node) {
        if(node == nullptr) {
            return;
        }

        in(node->left);
        ans.push_back(node->val);
        in(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        in(root);
        return ans;
    }
};


// #Iterative :-

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        TreeNode* node = root;

        while(node != nullptr || !st.empty()) {

            while(node != nullptr) {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();

            ans.push_back(node->val);

            node = node->right;
        }

        return ans;
    }
};
