/*
Leet Code - 545 :- Boundary Traversal.
So approach was like :-
1. Created three helper gunctions one which takes only left outward nodes and not the leaf nodes.
2. One takes all the leaf nodes used bfs for that.
3. Takes all right outward nodes and not leaf nodes.
4. Then we simply reversed the right ones nodes and merged all three in single vector along with root in starting followed by left,leaf,right(reversed).
5. Finally we returned the answer.

Time Complexity : O(n) .
Space Complexity : O(n) .

*/

class Solution {
public:

    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans3;

    void leftnodes(TreeNode* root) {
        TreeNode* node = root->left;

        while(node != nullptr) {

            if(!(node->left == nullptr && node->right == nullptr)) {
                ans1.push_back(node->data);
            }

            if(node->left != nullptr)
                node = node->left;
            else
                node = node->right;
        }
    }

    void leafnodes(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node->left == nullptr && node->right == nullptr) {
                ans2.push_back(node->data);
            }

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }
    }

    void rightnodes(TreeNode* root) {
        TreeNode* node = root->right;

        while(node != nullptr) {

            if(!(node->left == nullptr && node->right == nullptr)) {
                ans3.push_back(node->data);
            }

            if(node->right != nullptr)
                node = node->right;
            else
                node = node->left;
        }
    }

    vector<int> boundary(TreeNode* root) {
        if(root == nullptr)
    return {};

if(root->left == nullptr && root->right == nullptr)
    return {root->data};

        if(root == nullptr)
            return {};

        vector<int> ans;
        ans.push_back(root->data);

        leftnodes(root);
        leafnodes(root);
        rightnodes(root);

        ans.insert(ans.end(), ans1.begin(), ans1.end());
        ans.insert(ans.end(), ans2.begin(), ans2.end());

        reverse(ans3.begin(), ans3.end());

        ans.insert(ans.end(), ans3.begin(), ans3.end());

        return ans;
    }
};
