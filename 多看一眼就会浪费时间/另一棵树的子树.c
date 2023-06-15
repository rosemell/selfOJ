https://leetcode.cn/problems/subtree-of-another-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isNode(struct TreeNode*root,struct TreeNode*subRoot)
{
    if(NULL==root&&NULL==subRoot)
    {
        return true;
    }
    if(NULL==root||NULL==subRoot)
    {
        return false;
    }
    if(root->val!=subRoot->val)
    {
        return false;
    }
    return isNode(root->left,subRoot->left)
            &&isNode(root->right,subRoot->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(NULL==root)
    return false;
    if(isNode(root,subRoot)==true)
    {
        return true;
    }
    else{
        return isSubtree(root->left,subRoot)
                ||isSubtree(root->right,subRoot);
    }
}