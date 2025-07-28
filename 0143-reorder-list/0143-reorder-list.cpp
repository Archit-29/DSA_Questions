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
    void reorderList(ListNode* head) {

        if (!head || !head->next) return;

        ListNode*slow=head;
        ListNode*fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*curr=slow->next;
        slow->next=NULL;
        ListNode*prev=NULL;
        while(curr){
            ListNode*front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }

        ListNode*left=head;
        ListNode*right=prev;

        while(left && right){
            ListNode*node1=left->next;
            ListNode*node2=right->next;
            left->next=right;   
            right->next=node1;
            left=node1;
            right=node2;
        }
    }
};