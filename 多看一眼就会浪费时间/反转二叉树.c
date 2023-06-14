https://leetcode.cn/problems/invert-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//感觉...不如不改
struct TreeNode* invertTree(struct TreeNode* root){
    if(NULL==root)
    {
    return root;
    }
    struct TreeNode*left =invertTree(root->left);
    root->left=invertTree(root->right);
    root->right=left;
    return root;
}

//自己的没get到点的写法
// void swap(struct TreeNode**p1,struct TreeNode**p2)
// {
//     struct TreeNode*temp=*p1;
//     *p1=*p2;
//     *p2=temp;
// }
// struct TreeNode* invertTree(struct TreeNode* root){
//     if(NULL==root)
//     {
//     return root;
//     }
//     swap(&root->left,&root->right);
//     invertTree(root->left);
//     invertTree(root->right);
//     return root;
// }