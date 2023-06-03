https://leetcode.cn/problems/linked-list-cycle-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//����
struct ListNode *detectCycle(struct ListNode *head){
     if(NULL==head||NULL==head->next)
   {
        return NULL;
   }
    struct ListNode*fast=head,*slow=head;
    while(fast&&fast->next)//��fast��low���뻷������ͬһλ��
    {
        
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            fast=head;
            while(fast!=slow)
    {
        fast=fast->next;
        slow=slow->next;
    }return fast;
        }

    }
    
    return NULL;
}


//�Լ�һ��ʼѧ�˻�������1�������ĵ��ٷ���
// struct ListNode *detectCycle(struct ListNode *head) {
//     if(NULL==head||NULL==head->next)
//    {
//         return NULL;
//    }
//     struct ListNode*fast=head->next->next,*slow=head;
//     while(fast!=slow)//��fast��low���뻷������ͬһλ��
//     {
//         if(NULL==fast||NULL==fast->next)
//         {
//             return NULL;
//         }
//         fast=fast->next->next;
//         slow=slow->next;
//     }

//     int i=1;//��fast׷һȦslow����һ��Ȧ��Ԫ�ظ���
//     fast=fast->next->next;
//     slow=slow->next;
//     for(i=1;fast!=slow;i++)
//     {
//         fast=fast->next->next;
//         slow=slow->next;
//     }
//     fast=head;
//     slow=head;
//     for(;i;i--)
//     {
//         fast=fast->next;
//     }
//     while(fast!=slow)
//     {
//         fast=fast->next;
//         slow=slow->next;
//     }
//      return fast;
// }