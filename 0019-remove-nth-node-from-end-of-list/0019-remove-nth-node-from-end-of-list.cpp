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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // ListNode* temp=head;
       //  int count=0;
       //  while(temp!=NULL)
       //  {
       //      count++;
       //      temp=temp->next;
       //  }
       //  if(count==n)
       //  {
       //      ListNode* newHead=head->next;
       //      delete(head);
       //      return newHead;
       //  }
       //   count=count-n;
       //  temp=head;
       //  int count2=0;
       //  while(temp!=NULL){
       //      count2++;
       //      if(count2==count){
       //          break;
       //      }
       //      temp=temp->next;
       //  }
       //  ListNode* delNode=temp->next;
       //  temp->next=temp->next->next;
       //  delete(delNode);
       //  return head;
        
        ListNode* fast=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        ListNode* slow =head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete(delNode);
        return head;
    }
};