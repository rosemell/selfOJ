https://leetcode.cn/problems/copy-list-with-random-pointer/submissions/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

//������ⷽ������ÿ���ڵ�󴴽�һ���µĽڵ㣬��ô�½ڵ�����ָ��ָ��ľ�����һ����������ָ��ָ��ڵ����һ���ڵ�
struct Node* copyRandomList(struct Node* head)
{
    if(NULL==head)
    {
        return NULL;
    }
    struct Node* cur = head,*next;
    while (cur)
    {
        next = cur->next;
        cur->next = (struct Node*)malloc(sizeof(struct Node));
        cur->next->val = cur->val;
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    while(cur)
    {
        if (NULL==cur->random)
        {
            cur->next->random = NULL;
        }
        else
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    struct Node* newhead=head->next,*newcur = newhead,*newnext;
    next ;
    cur = head;
    while (newcur->next)
    {
        newnext = newcur->next->next;
        next = cur->next->next;
        cur->next = next;
        newcur->next = newnext;
        cur = next;
        newcur = newnext;
    }
    cur->next = NULL;
    return newhead;
}
//ֻ������32λ������
// struct Node* copyRandomList(struct Node* head) {
//     if(NULL==head)
//     {
//         return NULL;
//     }
//     struct Node*newhead=(struct Node*)malloc(sizeof(struct Node)),*cur=head,*newcur=newhead;
//     //�������������������val�����������У���������ĵ�ַ�������λ�õľ������val��
//     while(1)
//     {
//         newcur->val=cur->val;
//         newcur->random=cur;
//         cur->val=(int)newcur;

//         if(cur->next==NULL)
//         {
//             newcur->next=NULL;
//             break;
//         }
//         else
//         {
//         newcur->next=malloc(sizeof(struct Node));
//         }
//         cur=cur->next;
//         newcur=newcur->next;
//     }
//     cur=head;
//     newcur=newhead;
//     while(newcur)//���±�������
//     {
//         if(NULL==cur->random)
//         {
//             newcur->random=NULL;
//         }
//         else{
//         newcur->random=(struct Node*)cur->random->val;
//         }
//         cur=cur->next;
//         newcur=newcur->next;
//     }
//     return newhead;
// }