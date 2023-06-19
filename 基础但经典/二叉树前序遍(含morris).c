https://leetcode.cn/problems/binary-tree-preorder-traversal/



//������������ͺ���Ľ����ѧ��Morris����
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



//Morris�㷨
 int* preorderTraversal(struct TreeNode* root, int* returnSize){
     int *a=(int*)malloc(sizeof(int)*100000);
     *returnSize=0;
     if(NULL==root)
     return a;
     struct TreeNode*MostRight=NULL,*cur=root;
     while(cur!=NULL)
     {
         if(NULL==cur->left)//�жϽڵ���û��������
         {
             a[(*returnSize)++]=cur->val;
             cur=cur->right;
         }
         else//��������
         {
             for(MostRight=cur->left;NULL!=MostRight->right&&cur!=MostRight->right;MostRight=MostRight->right)//�ҵ������������ҽڵ�
             {
                 ;
             }
             if(NULL==MostRight->right)
                 {
                     a[(*returnSize)++]=cur->val;
                    MostRight->right=cur;
                    cur=cur->left;
                }
             if(cur==MostRight->right)//˵���˽ڵ��������Ѿ��������������ҽڵ㸴ԭ��������һ��
                {
                    MostRight->right=NULL;
                    cur=cur->right;
                }
        }
     }

     return a; 
 }





//����
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


//�Լ�д�ĵݹ�
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