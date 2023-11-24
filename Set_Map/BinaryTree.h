#ifndef SET_MAP_BINARYTREE_H
#define SET_MAP_BINARYTREE_H

struct TreeNode
{
    int value;
    int sum;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), sum(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : value(x), sum(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
    ~TreeNode()
    {
        delete right;
        delete left;
    }
};

void updateTreeSums(TreeNode* root)
{
    int currentSum = root->value;
    if (root->left)
    {
        updateTreeSums(root->left);
        currentSum += root->left->sum;
    }
    if (root->right)
    {
        updateTreeSums(root->right);
        currentSum += root->right->sum;
    }
    root->sum = currentSum;
}

#endif //SET_MAP_BINARYTREE_H