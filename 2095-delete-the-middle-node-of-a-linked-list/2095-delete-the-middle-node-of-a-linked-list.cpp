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
    ListNode* deleteMiddle(ListNode* head) {
       // int count=0;
       //  ListNode* temp=head;
       //  while(temp!=NULL){
       //      count++;
       //      temp=temp->next;
       //  }
       //  if(count%2==0){
       //      count=(count/2)+1;
       //  }else{
       //  count=count/2;}
       //  int count1=-1;
       //  temp=head;
       //  while(count1!=(count-1))
       //  {
       //      count1++;
       //      if(count1==count){
       //          break;
       //      }
       //      temp=temp->next;
       //  }
       //  ListNode* delNode=temp->next;
       //  temp->next=temp->next->next;
       //  delete(delNode);
       //  return head;
        
        //using slow and fast pointer
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* middle=slow->next;
        slow->next=slow->next->next;
        delete(middle);
        return head;
    }
};