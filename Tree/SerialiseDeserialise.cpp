/*
Leet Code - 297 :- Serialise and deserialise binary tree.
So approach was like :-
1. For Serialising we followed the level order traversal like we did like took an empty string and pushed all the nodes to the empty string
along with the commas and then we simply kept following the level order traversal and pushed # for nullptrs.
2. Then for deserialisation we did like converted string to stringstream and at each , we traversed each string using getlines and this way we 
got each node and and kept setting each left and right pointers using a queue where we pushed each time a new node is added to the tree.

Time Complexity : O(n) .
Space Complexity : O(n) .

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "";
        }
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node==nullptr){
                s.append("#,");
            }
            else{
                s.append(to_string(node->val)+',');
            }
            if(node!=nullptr){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size()==0){
        return nullptr;
       }
       stringstream s(data);
       string str;
       getline(s,str,',');
       TreeNode*root=new TreeNode(stoi(str));
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            node->left=nullptr;
        }
        else{
            TreeNode*leftnode=new TreeNode(stoi(str));
            node->left=leftnode;
            q.push(leftnode);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right=nullptr;
        }
        else{
            TreeNode*rightnode=new TreeNode(stoi(str));
            node->right=rightnode;
            q.push(rightnode);
        }
       }
       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
