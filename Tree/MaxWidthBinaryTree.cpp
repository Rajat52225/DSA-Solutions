/*
Leet Code - 662 :- Maximum width of binary tree.
So here we followed approach of the bfs.
1. We did like along with nodes at each level we also stored there index from left to right .
2. We say like if its n for parent then for left child and right child index is 2n+1 and 2n+2 respectively.
3. So this way for each level we checked the width by firstindex - lastindex of each level and kept storing the max one.
4. So this way we finally returned the max width.

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans=INT_MIN;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long first=q.front().second;
            long long last=0;
            for(int i=0;i<n;i++){
            TreeNode*node=q.front().first;
            long long curr=q.front().second-first;
            if(node->left){
                q.push({node->left,2*curr+1});
            }
           if(node->right){
                q.push({node->right,2*curr+2});
            }
            q.pop();
            last=curr;
            }
            ans=max(ans,(int)(last+1));
        }
        return ans;
    }
};
