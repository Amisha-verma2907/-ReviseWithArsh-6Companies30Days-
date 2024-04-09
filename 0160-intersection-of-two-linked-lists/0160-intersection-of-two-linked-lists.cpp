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
    // ListNode* collision(ListNode* node1,ListNode*node2,int diff){
    //     while(diff--)
    //     {
    //         node2=node2->next;
    //     }
    //     while(node1!=node2){
    //         node1=node1->next;
    //         node2=node2->next;
    //     }
    //     return node1;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //using hashing in this time complexity and space complexity is more
//         unordered_map<ListNode*,int>mp;
//         ListNode * temp=headA;
//         while(temp!=NULL){
//             mp[temp]=1;
//             temp=temp->next;
//         }
//         temp=headB;
//         while(temp!=NULL){
//         if(mp.find(temp)!=mp.end()){
//             return temp;
//         }
//             temp=temp->next;
//             }
        
//         return NULL;
     
        
        //using second approach sc:O(1) and TC:O(N1+2N2);
//         ListNode * temp1=headA;
//         ListNode * temp2=headB;
//         int N1=0,N2=0;
//         while(temp1!=NULL){ //O(N1) N1=cnt1;
//            N1++;
//             temp1=temp1->next;
//         }
        
//         while(temp2!=NULL){  //O(N2) N2=cnt2
//             temp2=temp2->next;
//             N2++;
//         }
        
//         if(N2>N1){           //O(N2-N1)
//            return collision(headA,headB,N2-N1);
            
//         }else{
//             return collision(headB,headA,N1-N2);
//             }
        
//         return NULL;
        
        
        //using third appraoch
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            
            if(temp1==temp2){
                return temp1;
            }
            
            if(temp1==NULL)
            {
                temp1=headB;
            }
            if(temp2==NULL){
                temp2=headA;
            }
        }
            
       return temp1;
        
    }
};