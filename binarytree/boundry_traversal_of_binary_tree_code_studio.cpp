#include<queue>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leftPrint(TreeNode<int> *root,vector<int>& ans){
    if(!root||(root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if (root->left){

        leftPrint(root->left, ans);
    }
    else{

        leftPrint(root->right, ans);
    }
}

void leafPrint(TreeNode<int> *root, vector<int> &ans) {
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    leafPrint(root->left,ans);
    leafPrint(root->right,ans);
}

void rightPrint(TreeNode<int> *root,vector<int>& ans){
    if(!root||(root->left==NULL && root->right==NULL)){
        return;
    }
    if (root->right){
        rightPrint(root->right, ans);
    }
    else{

        rightPrint(root->left, ans);
    }
    ans.push_back(root->data);
}


vector<int> traverseBoundary(TreeNode<int> *root)
{
    
	// Write your code here.
    vector<int>ans;
    if(!root){
        return ans;
    }
    ans.push_back(root->data);
    if(root->left!=NULL){
        leftPrint(root->left,ans);
    }
    leafPrint(root,ans);
    if(root->right){
        rightPrint(root->right,ans);
    }
    
    return ans;
}
