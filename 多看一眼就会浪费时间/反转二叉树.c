https://leetcode.cn/problems/invert-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//�о�...���粻��
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

//�Լ���ûget�����д��
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