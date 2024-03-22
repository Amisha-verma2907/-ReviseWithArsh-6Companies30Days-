/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //using hashing in this time complexity and space complexity is more
        unordered_map<ListNode*,int>mp;
        ListNode * temp=headA;
        while(temp!=NULL){
            mp[temp]=1;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
            temp=temp->next;
            }
        
        return NULL;
     
        
        //using second approach sc:O(1) and TC:O(N1+2N2);
        ListNode * temp1=headA;
        ListNode * temp2=headB;
        int N1=0,N2=0;
        while(temp1!=NULL){ //O(N1) N1=cnt1;
           N1++;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL){  //O(N2) N2=cnt2
            temp2=temp2->next;
            N2++;
        }
        
        if(N2>N1){
            temp2=headB;
            int diff=N2-N1;
            while(diff--){
               temp2=temp2->next; 
            }
        }else{
            temp1=headA;
            int diff=N1-N2;
            while(diff--){
                temp1=temp1->next;
            }
        }
        
            
       while(temp1!=temp2){
           temp1=temp1->next;
           temp2=temp2->next;
       }
        return temp1;
        
    }
};