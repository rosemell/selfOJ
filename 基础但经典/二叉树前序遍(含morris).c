https://leetcode.cn/problems/binary-tree-preorder-traversal/



//当初在这个博客和题的解答里学的Morris遍历
//https://blog.csdn.net/liujia2115/article/details/109215284



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



//Morris算法
 int* preorderTraversal(struct TreeNode* root, int* returnSize){
     int *a=(int*)malloc(sizeof(int)*100000);
     *returnSize=0;
     if(NULL==root)
     return a;
     struct TreeNode*MostRight=NULL,*cur=root;
     while(cur!=NULL)
     {
         if(NULL==cur->left)//判断节点有没有左子树
         {
             a[(*returnSize)++]=cur->val;
             cur=cur->right;
         }
         else//有左子树
         {
             for(MostRight=cur->left;NULL!=MostRight->right&&cur!=MostRight->right;MostRight=MostRight->right)//找到左子树的最右节点
             {
                 ;
             }
             if(NULL==MostRight->right)
                 {
                     a[(*returnSize)++]=cur->val;
                    MostRight->right=cur;
                    cur=cur->left;
                }
             if(cur==MostRight->right)//说明此节点左子树已经遍历过，把最右节点复原并遍历另一个
                {
                    MostRight->right=NULL;
                    cur=cur->right;
                }
        }
     }

     return a; 
 }





//迭代
//  int* preorderTraversal(struct TreeNode* root, int* returnSize)
//  {
//      int *a=(int*)malloc(sizeof(int)*10000);
//      *returnSize=0;
//      if(NULL==root)
//      return a;

//      struct TreeNode*stack[10000],*node=root;
//      int top=0;
//      while(top>0||NULL!=node)
//      {
//      while(NULL!=node)
//      {
//      a[(*returnSize)++]=node->val;
//      stack[top++]=node;
//      node=node->left;
//      }
//      node=stack[--top]->right;
//      }
//      return a;
//  }


//自己写的递归
// void preoder(int *a,struct TreeNode*root, int*returnSize)
// {
//     if(NULL==root)
//     {
//         return ;
//     }
//     a[*returnSize]=root->val;
//     (*returnSize)++;
//     preoder(a,root->left,returnSize);
//     preoder(a,root->right,returnSize);
// }
// int* preorderTraversal(struct TreeNode* root, int* returnSize){
//     int *a=(int*)malloc(sizeof(int)*10000);
//     *returnSize=0;
//     preoder(a,root,returnSize);
//     return a;
// }