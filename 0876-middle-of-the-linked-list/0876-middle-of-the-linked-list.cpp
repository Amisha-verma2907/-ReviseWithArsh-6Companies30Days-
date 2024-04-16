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
    ListNode* middleNode(ListNode* head) {
     // ListNode* temp=head;
     //    int cnt=0;
     //    while(temp!=nullptr)
     //    {
     //        cnt++;
     //        temp=temp->next;
     //    }
     //    cnt=(cnt/2)+1;
     //    temp=head;
     //    int k=0;
     //    while(temp!=nullptr)
     //    {
     //        k++;
     //        if(cnt==k){
     //            head=temp;
     //            break;
     //        }
     //        temp=temp->next;
     //    }
     //   return head; 
        
       // ListNode* slow =  head;
       //   ListNode* fast =head;
       //  while(fast->next != NULL && fast != NULL){
       //      slow=slow->next;
       //      fast=fast->next->next;
       //  }
       //  return slow;
        
         ListNode *s=head;
        ListNode *f=head;
        while(f!=NULL&&f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
        
    }
};