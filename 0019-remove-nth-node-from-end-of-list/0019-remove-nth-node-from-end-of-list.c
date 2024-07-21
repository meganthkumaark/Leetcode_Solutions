/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp=head;
    struct ListNode* prev=NULL;
    int count=0;
    int i;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    n=(count-n);
    temp=head;
    if(n==0)
    {
        head=temp->next;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
    }
    free(temp);
    return head;
}