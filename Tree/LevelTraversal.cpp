/*
Leet Code-102 :- Binary Tree Level Order Traversal .
So the approach is of bfs we use a queue here.
1. Push the root in the queue.
2. Run the for loop for the size of queue inside a while loop.
3. While loop runs untill queue is empty and for loop runs for the size of queue like we put the element from front of queue as treenode.
4. Then we put the value in the level vector and pop it from the queue and we also push the left and rights of the node in queue for next level.
5. Then after each for loop we push the level vector in the ans vector and finally returns the answer.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                 if(node->right){
                    q.push(node->right);
                }
                q.pop();

            }
            ans.push_back(level);
        }
        return ans;
    }
};
