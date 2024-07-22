/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
struct ListNode  head;
    struct ListNode   *h=&head;
    if(list1==NULL && list2==NULL)
        return NULL;
    
    while(list1 && list2){
        if(list1->val < list2->val){
          h->next=list1;
            list1=list1->next;
            h=h->next;
        }
        else
        {
            h->next=list2;
            list2=list2->next;
            h=h->next;
        }
    }
    if(list1){
        h->next=list1;
        }
    if(list2){
        h->next=list2;
    }
    return head.next;
    }