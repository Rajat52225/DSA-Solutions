/*
Leet Code - 103 :- Find the zigzag traversal .

So approach is like :-

1. Do same as we do bfs for level order just use a flag variable initially as 0.
2. When flag==1 just reverse the level vector and push in the ans and change flag to 0 .
3. When flag is 0 push as it is and change flag to 1.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        int flag=1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>res;
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                res.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
            if(flag==1){
                ans.push_back(res);
                flag=0;
            }
            else{
                reverse(res.begin(),res.end());
                ans.push_back(res);
                flag=1;
            }
        }
        return ans;
    }
};
