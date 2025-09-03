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
        int length=1;
        ListNode*temp=head;

        if(k==0 || head==NULL) return head;

        while(temp->next!=NULL){
            temp=temp->next;
            length++;
        }

        temp->next=head;
        
        int prev= length - (k%length)-1;
        temp=head;

        while(prev>0){
            prev--;
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};