https://leetcode.cn/problems/univalued-binary-tree/solutions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



bool isUnivalTree(struct TreeNode* root){
    if(NULL==root)
    return true;
    if(root->left)
    {
        if(root->left->val!=root->val)
        {
            return false;
        }
        if (isUnivalTree(root->left)==false)
        return false;
    }
    if(root->right)
    {
        if(root->right->val!=root->val)
        {
            return false;
        }
        if (isUnivalTree(root->right)==false)
        return false;
    }
        return true;
}