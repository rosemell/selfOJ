https://leetcode.cn/problems/linked-list-cycle-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//抄的
struct ListNode *detectCycle(struct ListNode *head){
     if(NULL==head||NULL==head->next)
   {
        return NULL;
   }
    struct ListNode*fast=head,*slow=head;
    while(fast&&fast->next)//让fast和low进入环并处于同一位置
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


//自己一开始学了环形链表1做出来的低速方法
// struct ListNode *detectCycle(struct ListNode *head) {
//     if(NULL==head||NULL==head->next)
//    {
//         return NULL;
//    }
//     struct ListNode*fast=head->next->next,*slow=head;
//     while(fast!=slow)//让fast和low进入环并处于同一位置
//     {
//         if(NULL==fast||NULL==fast->next)
//         {
//             return NULL;
//         }
//         fast=fast->next->next;
//         slow=slow->next;
//     }

//     int i=1;//让fast追一圈slow，数一下圈中元素个数
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