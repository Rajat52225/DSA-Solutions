/*
Leet Code-144 :- find preorder traversal of binary search tree.
So we have two approaches:-
1. Recusrive.
2. Iterative.

#Recursive approach:-
1. We return if node points to nullptr.
2. We push Node->val to ans.
3. We apply recursion on nodes->left and then on nodes->right and continue like this .
4. Finally we return the answer.

Time Complexity : O(n) .
Space Complexity : O(h) .

#Iterative approach:-
1. So in this we use a stack .
2. First we put root in stack .
3. Then we run loop until tstack aint empty.
4. We pops top element and pushes in answer .
5. We also then push right and then left of node in stack if not null.
6. We continue untill stack is empty and finally returns the answer .

Time Complexity : O(n) .
Space Complexity : O(h) .

*/

#Recursive :-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<int>ans;
   void pre(TreeNode* node){
    if(node==nullptr){
        return;
    }
    ans.push_back(node->val);
    pre(node->left);
    pre(node->right);
   }
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return ans;
    }
};

#Iterative :-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
       if(root==nullptr){
        return ans;
       }
       stack<TreeNode*>st;
       st.push(root);
       while(!st.empty()){
        TreeNode*node=st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
       }
       return ans;
    }
};

