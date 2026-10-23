/*
Leet Code - 235 :- Find the LCA in BST.
So appraoch was simple kept the 4 cases .
1. Stored the large value and small value among the p and q in two variables l and s.
2. First case did like if roots value is larger then largest then move left.
3. Second case was if roots value is smaller than smallest than move right.
4. Third case was if the root value falls between large and small then return root as answer.
5. Last case was if the root value if equal to either of large or small just return the root.

Time Complexity : O(h) .
Space Complexity : O(1) .

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l=max(p->val,q->val);
        int s=min(p->val,q->val);
        while(root!=nullptr){
            if(root->val<s){
                root=root->right;
            }
            else if(root->val>l){
                root=root->left;
            }
            else if(root->val>s && root->val<l ){
                return root;
            }
            else if(root->val==s || root->val==l){
                return root;
            }
        }
        return nullptr;
    }
};
