/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp=head;
        if(head == NULL || k==0)
            return head;
        int n=0;
        while(temp->next != NULL)
        {
            temp=temp->next;
            n++;
        }
        temp->next = head;
        k= k%(n+1);

        int x=n-k;
        temp=head;
        while(x)
        {
            temp=temp->next;
            x--;
        }
        ListNode *head1=temp->next;
        temp->next=NULL;
        return head1;
        
    }
};