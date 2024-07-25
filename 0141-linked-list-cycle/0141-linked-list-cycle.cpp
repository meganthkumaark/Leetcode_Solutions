
class Solution {
public:
    bool hasCycle(ListNode *head) {

if(head==NULL)
    return false;
struct ListNode *fast=head;
struct ListNode *slow=head;
int flag=0;
while(fast!=NULL&&fast->next!=NULL)
{
    fast=fast->next->next;
    slow=slow->next;
    
    if(fast==slow){
        flag=1;
        break;
    }
     //   return true;
    
    }
    if(flag==1){
        return true;
    }
    else{
        return false;
    }
    }
};
        
    
