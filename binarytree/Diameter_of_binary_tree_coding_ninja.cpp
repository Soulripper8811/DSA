/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };




************************************************************/
//trick is left side ka pura diamter and right side ka pura diamter and for both side take height and final answer will be max of 3 of them.

pair<int,int> diameterFast(TreeNode<int> *root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }

    pair<int,int>left=diameterFast(root->left);
    pair<int,int>right=diameterFast(root->right);

    int  op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}


int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.

return diameterFast(root).first-1;
}
