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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* kthNode(ListNode* temp,int k){
        k-=1;
        while(temp!= NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp =head;
        ListNode* prevLast = NULL;
        while(temp!= NULL){
            ListNode* kth = kthNode(temp,k);
            if(kth == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            
            ListNode* nextNode = kth->next;
            kth->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kth;
            }else{
                prevLast->next = kth;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};