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

    ListNode* reverseLinkedList(ListNode* temp){
            ListNode*prev=NULL;
            while(temp!=NULL){
                ListNode*front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k=k-1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prevNode=NULL;    

        while(temp!=NULL){
            ListNode*KthNode=getKthNode(temp,k);

            if(KthNode ==NULL ){
                if(prevNode) prevNode->next=temp;
                    break;
            }

            ListNode* nextNode=KthNode->next;
            KthNode->next=NULL;
            reverseLinkedList(temp);

            if(temp==head){
                head=KthNode;
            }else{
                prevNode->next=KthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};