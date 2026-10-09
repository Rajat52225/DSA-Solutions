/*
Leet Code - 257 :- Root to leaf node all possible paths.
We use dfs plus backtracking here.
1. We create a function where we return if node is null .
2. We push the root in res vector .
3. We apply that take not take approach same as subsets on here.
4. We finally gets answer.

Time Complexity : O(n²) .
Space Complexity : O(n²) .

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
    vector<string>ans;
    void fn(TreeNode*node,string s){
        if(node==nullptr){
            return;
        }
        if(!s.empty()){
            s+="->";
        }
        s+=to_string(node->val);
        if(node->left==nullptr && node->right==nullptr){
            ans.push_back(s);
            return;
        }
        else{
            fn(node->left,s);
            fn(node->right,s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        fn(root,"");
        return ans;
    }
};
