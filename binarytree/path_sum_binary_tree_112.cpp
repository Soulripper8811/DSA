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
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(root==NULL){
        return false;
       }
       queue<pair<TreeNode*,int>>q;
       int ans=root->val;
       q.push({root,ans});
       while(!q.empty()){
        auto [temp,data]=q.front();
        q.pop ();
        if(temp->left==NULL&& temp->right==NULL){
            if(data==targetSum){
                return true;
            }else{
                continue;
            }
        }
        if(temp->left){
            q.push({temp ->left,data+temp->left->val});
        }
        if(temp->right){
            q.push({temp->right,data+temp->right->val});
        }
       }
       return false;
    }
};