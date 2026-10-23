/*
Leet Code - 98 :-Check if the givem Bst is valid or not.
SO approach is like we have a property of BST that its inorder traversal is always sorted .
1. So we will do like find the inorder traversal of the tree .
2. Then we just check if its in increasing order then its valid else not .

Time Complexity : O(n) .
Space Complexity : O(n) .

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
    bool isValidBST(TreeNode* root) {
        TreeNode*cur=root;
        stack<TreeNode*>st;
        vector<int>ans;
        while(cur!=nullptr || !st.empty()){
            while(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            ans.push_back(cur->val);
            cur=cur->right;
        }
        bool flag=true;
        for(int i=0;i+1<ans.size() && i<ans.size();i++){
              if(ans[i]>=ans[i+1]){
                 flag=false;
              }
        }
        return flag;
    }
};
