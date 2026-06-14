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
    ListNode* isReverse(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=NULL;

        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
       ListNode*fast=head;
       ListNode*slow=head;

       while(fast->next && fast->next->next){
         fast=fast->next->next;
         slow=slow->next;
       }
       ListNode*newHead=isReverse(slow->next);
       fast=head;

       while(newHead){
         if(newHead->val != fast->val){
            return false;
         }
         newHead=newHead->next;
         fast=fast->next;
       }
       return true;
    }
};