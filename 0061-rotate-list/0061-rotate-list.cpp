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
     ListNode* newLastNode( ListNode* head,int k){
        int cnt=1;
          ListNode* temp= head;
         while(temp != NULL){
             if(cnt==k)return temp;
             temp=temp->next;
             cnt++;
         }
         return temp;
     }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0){
            return head;
        }
        ListNode* tail = head;
        int len=1;
        while(tail->next != NULL){
            tail=tail->next;
             len+=1;
        }
        if(k%len == 0){
            return head;
        }
        k=k%len;
        tail->next= head;
        ListNode* temp = newLastNode(head,len-k);
        
        head=temp->next;
        temp->next= NULL;
        return head;
    }
};