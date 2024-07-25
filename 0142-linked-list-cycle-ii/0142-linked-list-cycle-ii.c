/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
struct ListNode* slow=head;
struct ListNode* fast=head;
struct ListNode* sp=head;
int pos=0;
while(slow && fast && fast->next)
{
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
    {
        while(sp!=fast)
        {
            sp=sp->next;
            fast=fast->next;
        }
        return sp;
    }
}
return NULL;
}