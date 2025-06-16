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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*curr=head;

        int length=1;
        while(curr->next!=NULL){
            curr=curr->next;
            length++;
        }
        curr->next=head;
        k =length - (k%length);
        while(k>0){
            curr=curr->next;
            k--;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};