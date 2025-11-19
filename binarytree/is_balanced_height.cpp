/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
pair<bool, int> check(TreeNode<int>* root) {
    if(root == NULL) return {true, 0};  // {balanced, height}

    auto left = check(root->left);
    auto right = check(root->right);

    bool balanced = left.first && right.first &&
                    abs(left.second - right.second) <= 1;

    int height = max(left.second, right.second) + 1;

    return {balanced, height};
}

bool isBalancedBT(TreeNode<int>* root){
    return check(root).first;
}
