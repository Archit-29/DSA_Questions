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
    ListNode*reverse(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=NULL;

        while(temp){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    ListNode*getKth(ListNode*head,int k){
        k--;
        ListNode*curr=head;
        while(curr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode*temp=head;
      ListNode*prevNode=NULL;

      while(temp!=NULL){
        ListNode*kthNode=getKth(temp,k);
        if(kthNode==NULL){
            if(prevNode) prevNode->next=temp;
            break;
        }
        ListNode* nextNode=kthNode->next;
        kthNode->next=NULL;
        reverse(temp);
        if(temp==head) head=kthNode;
        else{
          prevNode->next=kthNode;
        }
        prevNode=temp;
        temp=nextNode;
      }
      return head;
    }
};