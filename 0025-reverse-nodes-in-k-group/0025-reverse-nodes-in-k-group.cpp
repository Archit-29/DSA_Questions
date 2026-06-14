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

    ListNode* reverse(ListNode*head){
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

    ListNode* getkth(ListNode*head,int k){
        k=k-1;
        ListNode*curr=head;
        while(curr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*nextNode;
        ListNode*prevNode=temp;

        while(temp!=NULL){
            ListNode*KthNode=getkth(temp,k);

            if(KthNode==NULL){
                if(prevNode){
                    prevNode->next=temp;
                    break;
                }
            }

            nextNode= KthNode->next;
            KthNode->next=NULL;

            reverse(temp);
            if(temp==head){
                head=KthNode;
            }
            else{
                prevNode->next=KthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};