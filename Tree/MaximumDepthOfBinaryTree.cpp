/*
Leet Code - 104 :- Maximum depth of Binary tree.
So there are two approaches like:-
1. We can use level order method to count height.
2. We can use recursion.

##Recursion aprroach:-
1. Just return 0 if root==null.
2. Take a left and recrusive call for root->left.
3. Take  a right and recursive call for root->right.
4. Return 1+max(left,right).

Time Complexity : O(n) .
Space Complexity : O(h) .

*/

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
    int maxDepth(TreeNode* root) {
       if(root==nullptr){
        return 0;
       }
       int left=maxDepth(root->left);
       int right=maxDepth(root->right);
  
       return 1+max(left,right);
    }
};
