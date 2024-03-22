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
        
        //using hashing
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
//        ListNode *t1 = headA, *t2 = headB;

//         while (t1 != t2) {
//             t1 = (t1 == NULL) ? headB : t1->next;
//             t2 = (t2 == NULL) ? headA : t2->next;
//         }
//         return t1;  
    }
};