
https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking


#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <sys/types.h>
typedef char TDataType ;
typedef struct TreeNode
{
    TDataType val;
    struct TreeNode*left;
    struct TreeNode*right;
} Tree;
Tree* CreatTree(char *a,int size,int *pos )
{
    if('#'==a[*pos]||*pos>=size)
    {
        (*pos)++;
        return NULL;
    }
    Tree*new=(Tree*)malloc(sizeof(Tree));
    new->val=a[*pos];
    (*pos)++;
    new->left=CreatTree(a,size,pos);
    new->right=CreatTree(a,size,pos);
    return new;
}
void DestroyTree(Tree *root)
{
    if(NULL==root)
    return;
    DestroyTree(root->left);
    DestroyTree(root->right);
    free(root);
}
void print(Tree*root)
{
    if(NULL==root)
    return;
    print(root->left);
    printf("%c ",root->val);
    print(root->right);
}
int main() {
    char tree[101]="";
    int i=0;
    for(i=0;scanf("%c",&tree[i])!=EOF;i++)
    {
        ;
    }
    int *pos=0;
    Tree*root=CreatTree(tree,i ,&pos);   
    print(root);
    printf("\n");
    DestroyTree(root);
    return 0;
}